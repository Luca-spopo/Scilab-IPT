//made to work for mlists (hypermatrices)

//Author: Anirudh Katoch
//katoch.anirudh(at)gmail.com

function res = modified_if(condi)
	if(type(condi) == 17)
		res = condi(1);
		for i=2:size(condi, 3) do
			res = res & condi(:, :, i);
		end
	else
		if(condi)
			res = %t;
		else
			res = %f;
		end
	end
endfunction
