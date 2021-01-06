#include <iostream>
#include "smrt.hpp"

int main() {
    std::cout << "first" << std::endl;
    // constructor
    Smrt<int> p1 = Smrt<int>(new int);

    std::cout << "second" << std::endl;
    // constructor (no args)
    Smrt<int> p2;

    std::cout << "third" << std::endl;
    // constructor
    // move assignment operator
    // destructor
    p2 = Smrt<int>(new int);

    std::cout << "fourth" << std::endl;
    *p1 = 5;
    std::cout << *p1 << std::endl;

    // destructor
    // destructor
    return 0;
}
