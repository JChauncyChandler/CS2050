all: printer

printer: queue.o printer.o
	gcc printer.o queue.o -o queue
printer.o: printer.c queue.h
	gcc printer.c -c
queue.o: queue.c queue.h
	gcc queue.c -c
clean:
	rem *.0 list
