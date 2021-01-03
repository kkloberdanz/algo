#include <iostream>

template <typename T>
T func(T a) {
    return a + a;
}

enum Foo {
    A,
    B
};

enum class Bar {
    C,
    D
};

class Base {
private:
    int bar() {
        return 2;
    }

public:
    int foo() {
        return 1;
    }
};

class Child : public Base {
private:
    int bar() {
        return 3;
    }
public:
    int foo() {
        return 4;
    }
};

int main() {
    double x = 13.7891;
    std::string a = std::to_string(x);
    std::string b = std::to_string(int(x));
    std::cout << int(x) << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    auto y = static_cast<int>(x);
    std::cout << y << std::endl;
    int z = x;
    std::cout << "z = " << z << std::endl;
    std::cout << func(x) << std::endl;
    std::cout << func(y) << std::endl;
    std::cout << func(a) << std::endl;
    std::cout << func(b) << std::endl;
    std::cout << "sizeof(Foo) = " << sizeof(Foo) << std::endl;
    std::cout << "sizeof(Bar) = " << sizeof(Bar) << std::endl;
    std::cout << "sizeof('a') = " << sizeof('a') << std::endl;

    Child child;
    std::cout << "child.foo() = " << child.foo() << std::endl;
    return 0;
}
