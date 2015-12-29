function res = tryunix(a)
    res = unix(a);
    if(res<>0)
        error('Could not execute unix command: '+a)
    end
endfunction
