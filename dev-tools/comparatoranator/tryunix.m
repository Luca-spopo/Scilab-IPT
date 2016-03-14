%Something using tryunix MUST happen

function ret = tryunix(s)
    if(unix(s) ~= 0)
        error(strcat('Could not run unix command: ', s));
    end
    ret = 0;
end
