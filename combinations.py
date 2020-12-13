import copy


#def combinations(it):
#    n = len(it)
#    if n == 0:
#        return []
#    return combinations(it[:n])

def even(n):
    return n % 2 == 0


def odd(n):
    return not even(n)


def dbg(expr):
    value = eval(expr)
    print(f"{expr} ==", value)
    return value


def permutations(it):
    all_perms = []
    def _permutations(l, size, n):
        if size == 1:
            #all_perms.append(copy.copy(l))
            print(l)
        else:
            for i in range(size):
                _permutations(l, size - 1, n)
                if even(size):
                    l[0], l[size - 1] = l[size - 1], l[0]
                else:
                    l[i], l[size - 1] = l[size - 1], l[i]

    ll = list(it)
    _permutations(ll, len(ll), len(ll))
    return all_perms


if __name__ == '__main__':
    dbg("permutations([1,2,3])")

#    test_cases = [
#        [1,2,3]
#    ]
#    for l in test_cases:
#        print(combinations(l))
