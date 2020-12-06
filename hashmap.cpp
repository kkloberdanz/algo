#include <iostream>
#include <vector>
#include <forward_list>
#include <utility>
#include <cassert>

class HashMap {
private:
    struct Bucket {
        int key;
        int value;
    };

    std::vector<std::forward_list<Bucket>> buckets;

    // /!\ must be a bitmask of trailing ones /!\
    // for hash function optimization to work, which avoids an expensize
    // idiv instruction (~25 clock cycles on haswell) and instead
    // does a cheap bitmask (1 clock cycle)
    size_t num_buckets;

    size_t buckets_used;

    const size_t word_size = sizeof(size_t) * 8;

    constexpr size_t get_prime() {
        if (word_size == 64) {
            return 12471678340987216927UL;
        } else {
            return 2654435761UL;
        }
    }

    void set_new_ll(int key, int value) {
    }

public:
    HashMap() {
        num_buckets = 0xf; // for starters
        buckets_used = 0;
        buckets.resize(num_buckets + 1);
    }

    HashMap(size_t initial_size) {
        num_buckets = initial_size;
        buckets.resize(num_buckets + 1);
    }

    void set(int key, int value) {
        auto index = hash(key);
        auto &ll = buckets[index];
        if (ll.empty()) {
            Bucket new_bucket;
            new_bucket.key = key;
            new_bucket.value = value;
            ll.assign(1, new_bucket);
            buckets_used++;
        } else {
            auto it = ll.begin();
            auto before_end = ll.before_begin();
            if (key == 14) {
                std::cout << "here" << std::endl;
            }
            for (; it != ll.end(); ++it) {
                if (it->key == key) {
                    it->value = value;
                    return;
                }
                before_end++;
            }
            Bucket new_bucket;
            new_bucket.key = key;
            new_bucket.value = value;
            ll.insert_after(before_end, new_bucket);
        }
    }

    int get(int key) {
        auto index = hash(key);
        auto ll = buckets[index];

        auto it = ll.begin();
        for (auto &it : ll) {
            if (it.key == key) {
                return it.value;
            }
        }
        throw std::runtime_error("key not found on get");
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

    /*
    for (int i = 0; i < 100000; i++) {
        std::cout << m.hash(i) << std::endl;
    }
    */
    m.set(1, 4);
    std::cout << m.get(1) << std::endl;

    for (int i = 0; i < 1000; i++) {
        m.set(i, i);
    }

    for (int i = 0; i < 1000; i++) {
        assert(m.get(i) == i);
    }
}
#endif
