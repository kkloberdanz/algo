#include <iostream>
#include <cmath>

class HashMap {
private:
    int *arr;

    // /!\ must be a bitmask of trailing ones /!\
    // for hash function optimization to work, which avoids an expensize
    // div instruction (~25 clock cycles on haswell) and instead
    // does a cheap bitmask (1 clock cycle)
    size_t num_buckets;

    const size_t word_size = sizeof(size_t) * 8;

    constexpr size_t get_prime() {
        if (word_size == 64) {
            return 12471678340987216927UL;
        } else {
            return 2654435761UL;
        }
    }

public:
    HashMap() {
        num_buckets = 0xfff; // for starters
    }

    void set(int key, int value) {
    }

    size_t hash(size_t K) {
        const size_t a = get_prime();
        K ^= K >> (word_size - num_buckets);
        K = (a * K) >> (word_size - num_buckets);
        return K & num_buckets;
    }
};

#ifdef TEST_HASHMAP
int main() {
    HashMap m;

    for (int i = 0; i < 100000; i++) {
        std::cout << m.hash(i) << std::endl;
    }
}
#endif
