%random helpful tip:    drawnow('update'); %Flushes the files

inputFileName = input('Enter input file (Enter for stdin): ', 's');

fileID_input = 0;
if( ~isempty(strtrim(inputFileName)))
    [fileID_input, err3] = fopen(inputFileName, 'r');
end

finishup = onCleanup(@() cleaner());

if(fileID_input == -1)
        error(strcat('Could not open input file: ', err3))
end

if(menu('Do you want me to run the builder? (Runs GUI)', 'Yes', 'No') == 1)
	tryunix('scilab -f build.sce &> /dev/null');
end

tryunix('if [ ! -p goMatlab ]; then mkfifo goMatlab; fi');
tryunix('if [ ! -p goScilab ]; then mkfifo goScilab; fi');

tryunix('echo > scilogs.txt');
tryunix('echo > logs.txt');


%tryunix('scilab-cli -f sciScript.sce &> scilogs.txt &');
%God knows why this isnt working, open a new terminal and run the command yourself instead
%Making a hacky and temporary (haha) workaround.

hacky_temp_flag = 1;

while 1
    [fileID_sciin, err2] = fopen('sciin', 'w');
    if(fileID_sciin == -1)
        error(strcat('Could not open sciin: ', err2))
    end
    [cmdSci, cmdMat] = takeinput(fileID_input);
    
    if(strcmp(cmdSci,'mar jao plij'))
    	fprintf(fileID_sciin, '%s', 'exit();');
        fclose(fileID_sciin);
	   tryunix('echo FilthyIPC > goScilab');
        break;
    end
    fprintf(fileID_sciin, '%s', cmdSci);
    fclose(fileID_sciin);
    fprintf('\nsending goScilab')
    if(hacky_temp_flag == 1)
        tryunix('scilab-cli -f sciScript.sce &> scilogs.txt &');
	hacky_temp_flag = 0;
    end
    tryunix('echo FilthyIPC > goScilab'); % #1
    fprintf('\nsent goScilab')
    ans = strcat('This value was returned because the statement did not return anything decent.');
    try
        eval(strcat(cmdMat, ';'));
    catch exc
    end
    matOut = ans;
    save('matOut.mat', 'matOut', 'cmdMat');
    fprintf('\nWaiting on goMatlab')
    tryunix('cat goMatlab > /dev/null'); % #2
    fprintf('\ngot goScilab')
    
 end
