CXX = g++
OPT = -O2
CXXFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all
all: queue hashmap

queue: queue.cpp queue.hpp
	$(CXX) -o queue queue.cpp $(OPT) -ggdb3 $(CXXFLAGS)

hashmap: hashmap.cpp hashmap.hpp
	$(CXX) -o hashmap hashmap.cpp $(OPT) -ggdb3 $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f core
	rm -f hashmap
	rm -f queue
