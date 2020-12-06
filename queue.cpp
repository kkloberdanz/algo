#include <iostream>
#include "queue.hpp"

int main() {

    Queue<int> q;
    for (int i = 0; i < 3; i++) {
        std::cout << "pushing: " << i << std::endl;
        q.push(i);
    }

    for (int i = 0; i < 2; i++) {
        std::cout << "poping: " << q.pop() << std::endl;
    }

    for (int i = 3; i < 6; i++) {
        std::cout << "pushing: " << i << std::endl;
        q.push(i);
    }

    for (int i = 0; i < 2; i++) {
        std::cout << "poping: " << q.pop() << std::endl;
    }

    while (!q.empty()) {
        std::cout << "> " << q.pop() << std::endl;
    }

    try {
        // q should be empty, this should throw
        q.pop();
    } catch (std::exception &e) {
        std::cout << "successfully caught: " << e.what() << std::endl;
    }
}
