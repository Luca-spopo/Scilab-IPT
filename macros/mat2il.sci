//Author: Anirudh Katoch
//katoch.anirudh(at)gmail.com

//Function to convert a 3d/2d matrix to a list of 2D matrices
//Used to convert image matrices to a list that can be passed to the gateway functions

//This is the type unsafe version that is only for debug purposes
//Silently returns values as they are if they are not valid arguments.

function res=mat2il(a)
    if type(a)<=8 then //Catch if a 2D matrix
        res = list(a);
        return;
    elseif type(a)~=17 then //Catch if not a matrix at all
        res = a;
        return;
    elseif ndims(a)~=3 then //Catch if 4D (or higher) matrix
         res = a;
         return;
    end
    res = list(a(:, :, 1));
    for i=2:size(a,3) do
        res(i) = a(:, :, i);
    end
endfunction
