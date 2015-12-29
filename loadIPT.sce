exec macros/show.sci
exec macros/imshow.sci
exec macros/modified_if.sci
exec macros/cmp.sci
exec loader.sce
exec Octave/loader.sce
exec macros/il2mat.sci
exec macros/mat2il.sci
S = dir('macros/more')
for x=1:size(S(2), 1)
exec('macros/more/'+S(2)(x))
end
clear S
clear x
