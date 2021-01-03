CXX = g++
CC = gcc
OPT = -O3
CXXFLAGS = -Wall -Wextra -Wpedantic
CFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all
all: queue hashmap cons mymalloc smrt

queue: queue.cpp queue.hpp
	$(CXX) -o queue queue.cpp $(OPT) -ggdb3 $(CXXFLAGS)

hashmap: hashmap.cpp hashmap.hpp
	$(CXX) -o hashmap hashmap.cpp $(OPT) -ggdb3 $(CXXFLAGS)

cons: cons.cpp
	$(CXX) -o cons cons.cpp $(OPT) -ggdb3 $(CXXFLAGS)

smrt: smrt.hpp smrt.cpp
	$(CXX) -o smrt smrt.cpp $(OPT) -ggdb3 $(CXXFLAGS)

mymalloc: mymalloc.c
	$(CC) -o mymalloc mymalloc.c $(OPT) -ggdb3 $(CFLAGS)

.PHONY: clean
clean:
	rm -f core
	rm -f hashmap
	rm -f queue
	rm -f cons
	rm -f smrt
	rm -f mymalloc
