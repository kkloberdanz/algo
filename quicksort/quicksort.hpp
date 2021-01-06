#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <cstddef>

template <typename T>
static size_t partition(std::vector<T> &v, size_t lo, size_t hi) {
    auto pivot = v[hi];
    auto i = lo;
    for (auto j = lo; j < hi; j++) {
        if (v[j] < pivot) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[hi]);
    return i;
}

template <typename T>
static void rec_quicksort(std::vector<T> &v, size_t lo, size_t hi) {
    if (lo < hi) {
        size_t p = partition(v, lo, hi);
        rec_quicksort(v, lo, p);
        rec_quicksort(v, p + 1, hi);
    }
}

template <typename T>
void quicksort(std::vector<T> &v) {
    size_t lo = 0;
    size_t hi = v.size();
    return rec_quicksort(v, lo, hi);
}

#endif // QUICKSORT_HPP