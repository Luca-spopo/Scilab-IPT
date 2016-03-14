%Creates the Nx2 matrix of string cells for you so that you can pass it to dfa


inputFileName = input('Enter input file (Enter for stdin): ', 's');

fileID_input = 0;
if( ~isempty(strtrim(inputFileName)))
    [fileID_input, err3] = fopen(inputFileName, 'r');
end


if(fileID_input == -1)
		fileID_input = 1;
        error(strcat('Could not open input file: ', err3))
end
i=0;
clear ttd;
while 1

	i=i+1;

 [sci, mat] = takeinput(fileID_input);
    
    if(strcmp(sci,'mar jao plij'))
    	 break;
    end

    ttd{i, 1} = sci;
    ttd{i, 2} = mat;

end

fprintf('ttd is ready\n')
disp(ttd)
