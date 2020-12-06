#pragma once

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
