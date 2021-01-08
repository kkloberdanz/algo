CXX=g++
OPT=-O3 -ggdb3
CXXFLAGS=-Wall -Wextra -Wpedantic $(OPT)

.PHONY: release
release: quicksort

.PHONY: debug
debug: OPT=-O0 -ggdb3
debug: quicksort

test: test.cpp quicksort.hpp
	$(CXX) -o test test.cpp $(CXXFLAGS) -lboost_unit_test_framework

quicksort: quicksort.cpp quicksort.hpp
	$(CXX) -o quicksort $(CXXFLAGS) quicksort.cpp

.PHONY: clean
clean:
	rm -f quicksort
	rm -f core
	rm -f test
