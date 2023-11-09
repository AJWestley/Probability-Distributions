swig -python distributions.i
gcc -c -fPIC $(pkg-config --cflags --libs python3) distributions.c distributions_wrap.c
ld -shared -fPIC distributions.o distributions_wrap.o -o _distributions.so
rm distributions_wrap.c
rm distributions_wrap.o
rm distributions.o