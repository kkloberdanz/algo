CC=cc
CFLAGS=-Wall -Wextra -Wpedantic -ggdb3 -O0 -fsanitize=address

test: test.o ll.o
	$(CC) -o test test.o ll.o $(CFLAGS)

ll.o: ll.c ll.h
	$(CC) -o ll.o -c ll.c $(CFLAGS)

test.o: test.c ll.h
	$(CC) -o test.o -c test.c $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o
	rm -f test
	rm -f core
