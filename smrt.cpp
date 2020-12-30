#include <iostream>

#include "smrt.hpp"

Smrt<int> foo() {
    Smrt<int> s1(new int);

    *s1 = 15;

    std::cout << "it is: " << *s1 << std::endl;

    Smrt<int> s2;

    s2 = s1;
    std::cout << "s2 = " << *s2 << std::endl;

    *s2 = -1;
    std::cout << "s1 = " << *s1 << std::endl;

    Smrt<int> s3 = std::move(s2);
    Smrt<int> s4;

    s4 = std::move(s3);
    return s4;
}

void bar() {
    auto x = foo();
    std::cout << "x = " << *x << std::endl;
}

int main() {
    bar();
}
