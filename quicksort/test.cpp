#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

#include <boost/test/unit_test.hpp>

#include "quicksort.hpp"

BOOST_AUTO_TEST_CASE(test_rand) {
    srand(42);
    for (size_t niter = 0; niter < 1000; niter++) {
        std::vector<int> v;
        for (size_t i = 0; i < 10000; i++) {
            v.push_back(rand() & 0xff);
        }
        auto copy = v;
        quicksort(v);
        std::sort(copy.begin(), copy.end());
        BOOST_CHECK(v == copy);
    }
}

BOOST_AUTO_TEST_CASE(test_small) {
    std::vector<int> v;
    print_vec(v);

    for (int i = 0; i < 10; i++) {
        v.push_back(i & 0xf);
    }

    print_vec(v);

    quicksort(v);
    std::vector<int> actual {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    BOOST_CHECK(v == actual);

    print_vec(v);

    std::vector<int> v2 {1,0,4,6,7,345,4,6453,6345634};
    print_vec(v2);
    quicksort(v2);
    std::vector<int> actual2 {0, 1, 4, 4, 6, 7, 345, 6453, 6345634};
    BOOST_CHECK(v2 == actual2);
    print_vec(v2);
}