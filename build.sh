llvm-gcc midi-au.c -framework AudioUnit -framework AudioToolbox -framework CoreMidi -framework CoreFoundation -o au
llvm-gcc -shared pymidiau.c $(python3-config --include) -lpython -o pymidiau.so