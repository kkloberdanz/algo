#include <iostream>
#include <vector>

#include "quicksort.hpp"

int main() {
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

    std::cout << "done" << std::endl;
}