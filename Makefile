CC ?= cc
CFLAGS ?= -O0 -fno-stack-protector

bunny: bunny.c
	$(CC) $(CFLAGS) -o bunny bunny.c

clean:
	rm -f bunny
