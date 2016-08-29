all: runner

runner: bst.o runner.o
	gcc runner.o bst.o -o bst
runner.o: runner.c bst.h
	gcc runner.c -c
bst.o: bst.c bst.h
	gcc bst.c -c
clean:
	rem *.0 list
