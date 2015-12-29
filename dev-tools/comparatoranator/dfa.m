%Takes a 2 wide vector of cell strings to execute, and provides input data for various values of img, imgH etc taken from all the images of a directory

%goes to cdto
%for all files that are not a directory
%  dumps the loading of the file, and metadata like height on to the file fd
%  dumps all the thingsToDo
%end
%come back to directory that it was called from

function dfa(thingsToDo, fd, prefix)
	
	cdto = prefix;

	before = pwd;
	cd(cdto);
	pwd

	arglist = dir();

	for index = arglist'
		if(index.isdir)
			continue
		end
		imgpath=index.name;
		fprintf(fd, '\n\n:s: img = imread(''%s''); imgH = size(img, 1); imgW = size(img, 2);', strcat(prefix, imgpath));
		fprintf(fd, '\n:m: img = imread(''%s''); imgH = size(img, 1); imgW = size(img, 2);', strcat(prefix, imgpath));
		for todo = 1:size(thingsToDo, 1)
			fprintf(fd, '\n\n:s: %s', thingsToDo{todo, 1});
			fprintf(fd, '\n:m: %s', thingsToDo{todo, 2});	
		end
	end

	cd(before);
end
