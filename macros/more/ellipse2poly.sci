//Function migration (image list to matrix) for: ellipse2poly
//Generated by migrate.cpp
//Author: Anirudh Katoch
function res = ellipse2poly(varargin)
	select length(varargin)
		case 08 then
			res = raw_ellipse2poly(varargin(01), varargin(02), varargin(03), varargin(04), varargin(05), varargin(06), varargin(07), varargin(08))
		else
			error(39)
	end
endfunction