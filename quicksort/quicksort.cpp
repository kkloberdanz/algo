#include <iostream>
#include <vector>

#include "quicksort.hpp"

template <typename T>
void print_vec(const std::vector<T> &v) {
    std::cout << "[";
    if (!v.empty()) {
        for (size_t i = 0; i < (v.size() - 1); i++) {
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size()];
    }
    std::cout << "]\n";
}

int main() {
    std::vector<int> v;
    print_vec(v);

    for (int i = 0; i < 10; i++) {
        v.push_back(i & 0xf);
    }

    print_vec(v);

    quicksort(v);

    print_vec(v);
}