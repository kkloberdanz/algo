CXX = g++
OPT = -O2

.PHONY: all
all: queue hashmap

queue: queue.cpp
	$(CXX) -o queue queue.cpp $(OPT) -g -DTEST_QUEUE

hashmap: hashmap.cpp
	$(CXX) -o hashmap hashmap.cpp $(OPT) -g -DTEST_HASHMAP
