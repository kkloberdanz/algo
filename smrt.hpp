#ifndef SMRT_HPP
#define SMRT_HPP

#include <atomic>

template<typename T>
class Smrt {
public:
    Smrt() {
        this->refs = nullptr;
        this->data = nullptr;
    }

    Smrt(T *ptr) {
        data = ptr;
        refs = new std::atomic<size_t>;
        *refs = 1;
    }

    ~Smrt() {
        if (refs) {
            (*refs)--;
            if (*refs == 0) {
                delete data;
                delete refs;
            }
        }
    }

    Smrt(const Smrt &obj) {
        data = obj.data;
        refs = obj.refs;
        (*refs)++;
    }

    Smrt(Smrt &&other) {
        this->data = other.data;
        this->refs = other.refs;
        other.data = nullptr;
        other.refs = nullptr;
    }

    Smrt &operator=(const Smrt &rhs) {
        if (this->data != rhs.data) {
            refs = rhs.refs;
            data = rhs.data;
            (*refs)++;
        }
        return *this;
    }

    Smrt &operator=(Smrt &&rhs) {
        refs = rhs.refs;
        data = rhs.data;
        rhs.data = nullptr;
        rhs.refs = nullptr;
        return *this;
    }

    T &operator*() {
        return *data;
    }

    T &operator->() {
        return data;
    }

private:
    T *data;
    std::atomic<size_t> *refs;
};

#endif // SMRT_HPP
