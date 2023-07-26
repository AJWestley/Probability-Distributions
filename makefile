CC ?= gcc
CFLAGS ?= -g -fopenmp -Wall -Wextra -pedantic
LDFLAGS ?= -lm

clean:
	rm -f $(wildcard *.o)
	rm -f $(wildcard /out.*.o)
