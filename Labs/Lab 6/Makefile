all: list

list: list.o runner.o
	gcc runner.o list.o -o list
runner.o: runner.c list.h
	gcc runner.c -c
list.o:	list.c list.h
	gcc list.c -c
clean:
	rem *.0 list
