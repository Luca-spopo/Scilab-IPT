// This file is released under the 3-clause BSD license. See COPYING-BSD.
function builder_gw_cpp()
    WITHOUT_AUTO_PUTLHSVAR = %t;

    
    tbx_build_gateway("skeleton_cpp", ..
    ["callOctave","callOctave"], ..
    ["s_o_test_v7.cpp"], ..
    get_absolute_file_path("builder.sce"),[],["-L/usr/lib/x86_64-linux-gnu -loctave -L/usr/lib/x86_64-linux-gnu -loctinterp"],["-I/usr/include/scilab -I/usr/include/octave-3.8.1/ -I/usr/include/octave-3.8.1/octave/"],[]);

//Original include was octave-4.0.0
//Ubuntu Trusty doesnt have it in the repo, so I downgraded it to /usr/include/octave-3.8.1

endfunction

builder_gw_cpp();
clear builder_gw_cpp; // remove builder_gw_cpp on stack
