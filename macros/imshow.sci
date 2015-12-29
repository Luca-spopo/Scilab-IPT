//Author  :Priyanka Hiranandani NIT Surat    
//TODO: Does not work for uint16 and uint32 type matrices.
function[] =imshow(Image)
    
	Image = mat2il(Image)	//This was put here by me to let this function take a 3d matrix directly.
				//I see that it later converts it back to a matrix anyway, which makes this conversion pretty pointless.
				//TODO: Optimize this function.
				//~Anirudh Katoch

    global TYPE_DOUBLE;         //retrieving list and creating 3 dimensional matrix out of it
    dimensions=size(Image)

    MaxUInt8 = 2 ^ 8 - 1;
    MaxUInt16 = 2 ^ 16 - 1;
    MaxUInt32 = 2 ^ 32 - 1;
    MaximumGrayValue = MaxUInt32;  

    if dimensions==3 then 
         matSize=size(Image(1));
         r=matrix(Image(1),matSize(1),matSize(2));
         g=matrix(Image(2),matSize(1),matSize(2));
         b=matrix(Image(3),matSize(1),matSize(2));


         z(:,:,1)=uint8(r);    //Since Matplot is not working with uint16 and uint32, convert every image to a 
         z(:,:,2)=uint8(g);    //8 bit palette.
         z(:,:,3)=uint8(b);    //Note: this will affect the color depth.


         [NumberOfRows NumberOfColumns NumberOfChannels] = size(z);
         NumberOfPixels = NumberOfRows * NumberOfColumns;
         Sample = z(1);
                  
	if type(Sample) == 1 then //type 1 = real/complex matrix of double
             ColorMap = matrix(z, NumberOfPixels, NumberOfChannels);
             disp(ColorMap); 
         else
            TypeName = typeof(Sample)
             select TypeName
                 case 'uint8' 
                    MaxGrayValue = MaxUInt8;
                 case 'uint16'
                    MaxGrayValue = MaxUInt16;
                 case 'uint32'
                    MaxGrayValue = MaxUInt32;
         end;  
         ColorMap = double(matrix(z, NumberOfPixels, NumberOfChannels)) / MaxGrayValue;
         end;       
         Img=z;

     //Grayscale
     elseif dimensions==1 then
         matSize = size(Image(1));
         Img=matrix(Image(1),matSize(1),matSize(2));
         Img=Img';
         select typeof(Img)
             case 'uint8' 
                MaximumGrayValue = MaxUInt8;
             case 'uint16'  
                MaximumGrayValue = max(Image(:));
             case 'uint32' 
                MaximumGrayValue = max(Image(:));                
        end;
     	ColorMap = graycolormap(double(MaximumGrayValue + 1));
     end;
     show(Img,ColorMap);
endfunction
