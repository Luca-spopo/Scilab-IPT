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
	catch e %I know very well just how ugly this is. But I can't think of any useful errors to catch besides the ones we are to ignore anyway.
	end

	try
	if(	sciCmd == -1 ) %I can't seem to figure out how the | operator works in this thing
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
	%no, maintainance of this code is not my priority right now.
	try
	if(isempty(strtrim(matCmd)))
		matCmd = sciCmd;
	end
	catch e %I know very well just how ugly this is. But I can't think of any useful errors to catch besides the ones we are to ignore anyway.
	end

	try
	if(	matCmd == -1 ) %I can't seem to figure out how the | operator works in this thing
		matCmd = sciCmd;
	end
	catch e
	end


	if(fd > 2)
		fprintf('\nComparing...\nscilab command: %s\nmatlab command: %s\n', sciCmd, matCmd);
	end
	

end