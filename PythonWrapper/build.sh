cp ../distributions.c distributions.c
cp ../distributions.h distributions.h
swig -python distributions.i
gcc -c -fPIC $(pkg-config --cflags --libs python3) distributions.c distributions_wrap.c
ld -shared -fPIC distributions.o distributions_wrap.o -o _distributions.so
rm distributions.c
rm distributions.h
rm distributions_wrap.c
rm distributions_wrap.o
rm distributions.o