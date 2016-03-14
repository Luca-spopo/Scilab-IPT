%Abstracts taking the input commands for us.
%Takes the "commands to run on scilab and matlab" from console or a file

function [sciCmd, matCmd] = takeinput(fd)
	matCmd = -1;
	if(fd > 2)
		fscanf(fd, '%*[\n]');
		fscanf(fd, ':s:');
		sciCmd = fgetl(fd);
	else
		sciCmd = input('Enter scilab command (or hit enter to exit): ', 's');
	end

	try
	if(isempty(strtrim(sciCmd)))
		sciCmd = 'mar jao plij' %this is hindi for "please die"
		matCmd = sciCmd;
		return;
	end
	catch e %I can't think of any useful errors to catch besides the ones we are to ignore anyway.
	end

	try
	if(	sciCmd == -1 ) %kicks in if eof was encountered.
		sciCmd = 'mar jao plij'
		matCmd = sciCmd;
		return;
	end
	catch e
	end


	if(fd > 2)
		fscanf(fd, ':m:');
		matCmd = fgetl(fd);
	else
		matCmd = input('Enter matlab command (press enter if same): ', 's');
	end

	%shameless copy paste
	try
	if(isempty(strtrim(matCmd)))
		matCmd = sciCmd;
	end
	catch e
	end

	try
	if(matCmd == -1 )
		matCmd = sciCmd;
	end
	catch e
	end


	if(fd > 2) %We need feedback on the screen, or things get boring.
		fprintf('\nComparing...\nscilab command: %s\nmatlab command: %s\n', sciCmd, matCmd);
	end
	

end
