#include <iostream>
#include <stack>

template <typename T>
class Queue {
private:
    std::stack<T> enq;
    std::stack<T> deq;

    void rebalance() {
        if (enq.empty()) {
            throw std::runtime_error("front of an empty queue");
        }
        while (!enq.empty()) {
            auto item = enq.top();
            deq.push(item);
            enq.pop();
        }
    }

public:
    T front() {
        if (deq.empty()) {
            rebalance();
        }
        return deq.top();
    }

    T pop() {
        auto item = front();
        deq.pop();
        return item;
    }

    void push(T item) {
        enq.push(item);
    }

    T back() {
        return enq.top();
    }

    bool empty() {
        return enq.empty() && deq.empty();
    }
};

#ifdef TEST_QUEUE
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
#endif
