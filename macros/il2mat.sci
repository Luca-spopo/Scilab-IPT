//Author: Anirudh Katoch
//katoch.anirudh(at)gmail.com

//Function to convert a list of matrices to a 3d hypermatrix
//Used to convert list retreived from gateway functions to image matrix
//Works for any number of channels. Each channel is an element of the list and is represented by a 2D matrix.

//This is the type unsafe version that is only for debug purposes
//Silently returns values as they are if they are not valid arguments.

function res = il2mat(a)
    if type(a)<>15 then //If a is not a list
        res = a;
        return a;
     end
     zmax = length(a);
     for zi=a do
         if type(zi)==15 or type(zi)==16 then
             //recursive stuff here, if you choose to do so.
             res = a;
             return a;
         elseif(type(zi)~=8) //I'm only allowing integer matrices. Tweak later for whatever type safety you want.
             res = a;
             return a;
         end
         if ~isequal(size(zi), size(a(1))) then
             res = a;
             return a;
         end
     end
     res = a(1);
     for zi=2:zmax do
         res(:, :, zi) = a(zi);
     end
endfunction
