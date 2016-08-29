all: plane

plane: lib.o runner.o
	gcc runner.o lib.o -o lib
runner.o: runner.c lib.h
	gcc runner.c -c
lib.o: lib.c lib.h
	gcc lib.c -c
clean: 
	rm *.0 list
