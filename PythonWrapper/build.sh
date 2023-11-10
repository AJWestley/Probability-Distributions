#!/bin/bash

# Copy C file and header
cp ../distributions.h distributions.h
cp ../distributions.c distributions.c

# Generate wrapper
swig -python distributions.i
gcc -c -fPIC $(pkg-config --cflags --libs python3) distributions.c distributions_wrap.c
ld -shared -fPIC distributions.o distributions_wrap.o -o _distributions.so

# Delete artifacts
rm distributions_wrap.c
rm distributions_wrap.o
rm distributions.o
rm distributions.h
rm distributions.c