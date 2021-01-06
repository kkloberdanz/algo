#include <iostream>
#include <vector>

class MyClass {
public:

    MyClass() {
        this->x = new int;
        *this->x = 0;
        std::cout << "constructor (no args): " << (*this->x) << std::endl;
    }

    // constructor
    MyClass(int x) {
        this->x = new int;
        *this->x = x;
        std::cout << "constructor: " << (*this->x) << std::endl;
    }

    // destructor
    ~MyClass() {
        std::cout << "destructor" << std::endl;
        delete x;
    }

    // copy constructor
    MyClass(const MyClass &obj) {
        this->x = new int;
        *this->x = *obj.x;
        std::cout << "copy constructor: " << *x << std::endl;
    }

    // copy assignment operator
    MyClass &operator=(const MyClass &rhs) {
        std::cout << "copy assingment operator: " << *x << std::endl;
        *this->x = *rhs.x;
        return *this;
    }

    // move constructor
    MyClass(MyClass &&rhs) {
        std::cout << "move constructor" << std::endl;
        this->x = rhs.x;
        rhs.x = nullptr;
    }

    // move assignment
    MyClass &operator=(MyClass &&rhs) {
        std::cout << "move assignment" << std::endl;
        this->x = rhs.x;
        rhs.x = nullptr;
        return *this;
    }

    int X() {
        return *x;
    }

private:
    int *x;
};

int main() {
    std::cout << "hello world!" << std::endl;

    MyClass c(-1);
    std::vector<MyClass> v;
    for (int i = 0; i < 10; i++) {
        //v.push_back(std::move(MyClass(i)));
        v.push_back(MyClass(i));
    }

    std::cout << "\nagain\n" << std::endl;

    std::vector<MyClass> v2;
    v2.reserve(10);
    for (int i = 0; i < 10; i++) {
        //v2.push_back(std::move(MyClass(i)));
        v2.push_back(MyClass(i));
    }

    std::cout << "\nresize\n" << std::endl;
    std::vector<MyClass> v3;
    v3.resize(10);
    for (int i = 0; i < 10; i++) {
        v3.push_back(MyClass(i));
    }

    MyClass c2(-4);
    MyClass c3(-5);
    c3 = c2;

    std::cout << c2.X() << std::endl;
    std::cout << c3.X() << std::endl;
    return 0;
}
