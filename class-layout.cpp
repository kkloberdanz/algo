#include <iostream>
#include <cstdint>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class Base1 {
public:
    Base1() {
        x = 0xdeadbeef;
        y = 0x12345678;
    }

    uint32_t Foo(uint32_t z) {
        return x + y + z;
    }

    virtual uint32_t Bar(uint32_t z) {
        return x + y * z;
    }

    virtual uint32_t Bar2(uint32_t z) {
        return x + y * z * 2;
    }
//private:
    uint32_t x;
    uint32_t y;
};

class Base2 {
public:
    Base2() {
        a = 0xabcdef12;
        b = 0x19283746;
    }
//private:
    uint32_t a;
    uint32_t b;
};

class Child : public Base1, public Base2 {
public:
    Child() {
        foo = 0x65443299;
        bar = 0x8548458a;
    }
//private:
    uint32_t foo;
    uint32_t bar;
};

int main() {
    Child child;
    Child *cptr = &child;
    int fd = open("Child.object", O_CREAT|O_WRONLY, 0666);
    write(fd, cptr, sizeof(Child));
    Child child2;
    cptr = &child2;
    cptr->x = 0;
    cptr->y = 0;
    cptr->a = 0;
    cptr->b = 0;
    cptr->foo = 0;
    cptr->bar = 0;
    write(fd, cptr, sizeof(Child));
    close(fd);
    //int *x = (int *)(0x00402028);
    //std::cout << "*x = " << *x << std::endl;
    //std::cout << "cptr = " << cptr << std::endl;
    //int *y = new int;
    //std::cout << "y = " << y << std::endl;
    return 0;
}
