#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "quicksort.hpp"

void test() {
    for (size_t niter = 0; niter < 1000; niter++) {
        std::vector<int> v;
        for (size_t i = 0; i < 10000; i++) {
            v.push_back(rand() & 0xff);
        }
        auto copy = v;
        quicksort(v);
        std::sort(copy.begin(), copy.end());
        if (copy != v) {
            std::cerr << "fail" << std::endl;
            print_vec(v);
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    srand(42);
    std::vector<int> v;
    print_vec(v);

    for (int i = 0; i < 10; i++) {
        v.push_back(i & 0xf);
    }

    print_vec(v);

    quicksort(v);

    print_vec(v);

    std::vector<int> v2 {1,0,4,6,7,345,4,6453,6345634};
    print_vec(v2);
    quicksort(v2);
    print_vec(v2);

    test();
    std::cout << "done" << std::endl;
}
