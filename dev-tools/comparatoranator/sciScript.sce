// http://help.scilab.org/docs/5.3.1/en_US/m2sci_eval.html

//Author: Anirudh Katoch
//katoch.anirudh(at)gmail.com
//Not proud of this.

//Rename the variables to ones with less chance of collisions

printf('SciScript.sce says hello world!');

try
	stacksize('max');
	exec tryunix.sci
	oldplace = pwd();
	cd ('../../');
	exec('loadIPT.sce');
	cd(oldplace)
	clear oldplace
	printf('SciScript.sce says he is fine!');
	fd_inp = mopen('logs.txt', 'w');
	if(fd_inp==-1)
		error("Couldnt open logs.txt for writing")
	end
catch
	printf('SciScript.sce had trouble loading some stuff. Are you sure you ran builder? Some files may be missing.')
end
try
	while (1)
		printf('\nWaiting for goScilab')
		tryunix('cat goScilab > /dev/null'); //#1
		printf('\nReceived goScilab')
		[fd, err] = mopen('sciin', 'r');
		if(fd==-1)
			unix('echo FilthyIPC > goMatlab');
			printf("Scilab could not open sciin: "+err);
		end
		txt = mgetl(fd);
		mclose(fd);
		ans = 'This value was returned because the statement did not return anything decent.';
		try
			//You're gonna have to detect an assignment operation and use eval or execstr accordingly :/
			//I'm using a hack for that. Let me describe the behavior of execstr
			//    execstr(string); is interpretted as ans = execstr(string); and does not return anything, making ans undefined
			//    but bla=exec(string); gives ans a value (if anonymous expression in string) or doesn't touch ans (if there was an assignment in string)
			//I am exploiting this.
			//Also, all calls such as printf etc will change ans to undefined, so be careful here onwards.
			kek = printf('Trying to execute string %s', txt)
			kek = execstr(txt);
			kek = printf('Executed string')
		catch
			kek = printf('\nScilab had trouble parsing %s :(\n', txt);
		end
		kek = printf('I am here.')
		if(~exists('ans'))
			ans = 'This value was returned because the statement did not return anything decent.';
		end
		x = ans;
		printf('\nsending goMatlab')
		tryunix('echo FilthyIPC > goMatlab'); //#2
		printf('\nSent goMatlab')
		loadmatfile('matOut.mat');
		cmp_answer = cmp(matOut, x)
		if(cmp_answer == 0)
			mfprintf(fd_inp, '\n\nMatch for scilab %s and matlab %s', txt, cmdMat)
		elseif (cmp_answer == 1)
			mfprintf(fd_inp, '\n\nMismatch for scilab %s and matlab %s', txt, cmdMat)
			printf('\nMismatch encountered:\n')
			disp(x);
			printf('\n\nand\n\n')
			disp(matOut);
		else
			mfprintf(fd_inp, '\n\nNothing to compare for scilab %s and matlab %s.', txt, cmdMat)
			printf('\nNothing to compare\n')
			disp(x);
			printf('\n\nand\n\n')
			disp(matOut);
		end
	end
catch
	mclose('all');
	[error_message,error_number]=lasterror(%t);
	printf('\nScilab encountered an error: %s', error_message)
	unix('echo die > goMatlab &');
	unix('echo die > goMatlab &');
	unix('cat goMatlab &');
	printf('\nERROR %d %s', error_number, error_message)
end
