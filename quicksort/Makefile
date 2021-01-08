CXX=g++
OPT=-O3 -ggdb3
CXXFLAGS=-Wall -Wextra -Wpedantic $(OPT)

.PHONY: release
release: quicksort

.PHONY: debug
debug: OPT=-O0 -ggdb3
debug: quicksort

quicksort: quicksort.cpp quicksort.hpp
	$(CXX) -o quicksort $(CXXFLAGS) quicksort.cpp

.PHONY: clean
clean:
	rm -f quicksort
	rm -f core
