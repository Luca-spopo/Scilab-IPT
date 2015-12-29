//Function migration (image list to matrix) for: threshold
//Author: Anirudh Katoch
function [res1, res2] = threshold(varargin)
	select length(varargin)
		case 4 then
			[res1, res2] = raw_threshold(mat2il(varargin(1)), varargin(2), varargin(3), varargin(4))
			res1 = il2mat(res1)
		else
			error(39)
	end
endfunction
