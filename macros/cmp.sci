//returns 0 when equal

//Redefine this function if you need to implement stuff like histogram difference etc while comparing the outputs
//As it is, it is pretty intolerant of any differences. I have implemented strcmp though.

//Author: Anirudh Katoch
//katoch.anirudh(at)gmail.com

function res = cmp(A, B)
	
	temp = 'This value was returned because the statement did not return anything decent.';
	try
		if(A==temp)
			res = -1; //Nothing to compare
			return
		end
	catch
	end
	try
		if(B==temp) //Didnt put them as (A == temp | B==temp) because one of them may throw an error. Entire expression is evaluated. It's not short circuit.
			res = -1; //Nothing to compare
			return
		end
	catch
	end
	try
		if(A==B)
			res = 0
			return
		end
	catch
	end
	try
		res = 1;
		// a difference of 1.0e-15 * -0.4441 was detected between some matlab and scilab outputs.
		// hence using A-B<threshold instead of A==B

		//If(condition) doesn't take mlists because it hates me.

		if (modified_if(abs(A-B)<0.00000001)) //But for some reason abs does.
			res = 0;
		end
	catch
		//This usually means the array sizes didnt match up.
		//or A-B didnt run for whatever reason.
		res = 1;
	end
endfunction
