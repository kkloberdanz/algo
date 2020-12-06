#include <iostream>
#include "hashmap.hpp"

int main() {
    HashMap<int, int> m;

    assert(m.haskey(1) == false);

//    for (int i = 0; i < 100000; i++) {
//        std::cout << m.hash(i) << std::endl;
//    }

    m.set(1, 4);
    assert(m.haskey(1) == true);
    std::cout << m.get(1) << std::endl;

    int nitems = 10000000;
    for (int i = 0; i < nitems; i++) {
        m.set(i, i);
    }

    for (int i = 0; i < nitems; i++) {
        assert(m.get(i) == i);
    }

    HashMap<std::string, int> m2;
    m2.set("hello", 15);
    std::cout << m2.get("hello") << std::endl;

    auto k2 = "aweklfajsdlfkjasrkl3ejrkljflkajsdlkfvjxcv lkjxcbvlkjlk";
    m2.set(k2, 21);
    std::cout << m2.get(k2) << std::endl;
}
