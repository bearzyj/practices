all: 1_basic.bin 2_boundary.bin

1_basic.bin: 1_basic.o
	gcc -o 1_basic.bin 1_basic.o

2_boundary.bin: 2_boundary.o
	gcc -o 2_boundary.bin 2_boundary.o

1_basic.o:

2_boundary.o:

clean:
	rm -rf *.bin *.o

.PHONY: all clean

