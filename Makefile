CXX = g++
OPT = -O0
CXXFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all
all: queue hashmap cons

queue: queue.cpp queue.hpp
	$(CXX) -o queue queue.cpp $(OPT) -ggdb3 $(CXXFLAGS)

hashmap: hashmap.cpp hashmap.hpp
	$(CXX) -o hashmap hashmap.cpp $(OPT) -ggdb3 $(CXXFLAGS)

cons: cons.cpp
	$(CXX) -o cons cons.cpp $(OPT) -ggdb3 $(CXXFLAGS)

smrt: smrt.hpp smrt.cpp
	$(CXX) -o smrt smrt.cpp $(OPT) -ggdb3 $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f core
	rm -f hashmap
	rm -f queue
	rm -f cons
	rm -f smrt
