CXX = g++

queue: queue.cpp
	$(CXX) -o queue queue.cpp -O2 -g -DTEST_QUEUE
