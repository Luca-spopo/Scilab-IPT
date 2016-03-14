function cleaner()
	unix('echo spam > goMatlab &');
	unix('echo spam > goMatlab &');
	unix('echo spam > goScilab &');
	unix('echo spam > goScilab &');
	unix('cat goMatlab > /dev/null');
	unix('cat goScilab > /dev/null');
	unix('rm sciin');
	unix('rm matOut.mat');
	unix('rm goScilab');
	unix('rm goMatlab');

	%Running the cleaner undos the build process, so I don't think
	%we should do it here. Uncomment the line below to run cleaner automatically
	
	%unix('scilab-cli -f clean.sce &> /dev/null');	
end