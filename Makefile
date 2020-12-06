CXX = g++
OPT = -O2

.PHONY: all
all: queue hashmap

queue: queue.cpp
	$(CXX) -o queue queue.cpp $(OPT) -ggdb3

hashmap: hashmap.cpp
	$(CXX) -o hashmap hashmap.cpp $(OPT) -ggdb3

.PHONY: clean
clean:
	rm -f core
	rm -f hashmap
	rm -f queue
