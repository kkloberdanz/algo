#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <cstddef>
#include <vector>

template <typename T>
void print_vec(const std::vector<T> &v) {
    std::cout << "[";
    if (!v.empty()) {
        for (size_t i = 0; i < (v.size() - 1); i++) {
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size() - 1];
    }
    std::cout << "]\n";
}

template <typename T>
static size_t partition(std::vector<T> &v, size_t lo, size_t hi) {
    auto pivot = v[hi];
    auto i = lo;
    for (auto j = lo; j < hi; j++) {
        if (v[j] <= pivot) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[hi]);
    return i;
}

template <typename T>
static void insertionsort(std::vector<T> &v, size_t lo, size_t hi) {
    for (size_t i = lo; i < hi + 1; i++) {
        size_t j = i;
        while ((j > 0) && (v[j-1] > v[j])) {
            std::swap(v[j], v[j-1]);
            j--;
        }
    }
}

template <typename T>
static void rec_quicksort(std::vector<T> &v, size_t lo, size_t hi) {
    if (lo < hi) {
        if ((hi - lo) < 56) {
            insertionsort(v, lo, hi);
        } else {
            size_t p = partition(v, lo, hi);
            rec_quicksort(v, lo, p - 1);
            rec_quicksort(v, p + 1, hi);
        }
    }
}

template <typename T>
void quicksort(std::vector<T> &v) {
    size_t lo = 0;
    size_t hi = v.size();
    return rec_quicksort(v, lo, hi - 1);
}

#endif // QUICKSORT_HPP
