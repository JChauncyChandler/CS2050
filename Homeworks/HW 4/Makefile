all = hw4
CC = gcc
CFLAGS = -g -Wall

$(all): runner.o bst.o stack.o queue.o 
	$(CC) runner.o bst.o stack.o queue.o -o $@
runner.o: runner.c bst.h
	$(CC) runner.c $(CFLAGS) -c -o $@
bst.o: bst.c bst.h
	$(CC) bst.c $(CLFAGS) -c -o $@
queue.o: queue.c queue.h 
	$(CC) queue.c $(CFLAGS) -c -o $@
stack.o: stack.c stack.h 
	$(CC) stack.c $(CFLAGS) -c -o $@
clean: 
	rm *.o $(all)


