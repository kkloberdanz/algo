number_to_letters = {
    '2': ['a', 'b', 'c'],
    '3': ['d', 'e', 'f'],
    '4': ['g', 'h', 'i'],
    '5': ['j', 'k', 'l'],
    '6': ['m', 'n', 'o'],
    '7': ['p', 'q', 'r', 's'],
    '8': ['t', 'u', 'v'],
    '9': ['w', 'x', 'y', 'z'],
}


def get_letter_sets(digits):
    return [number_to_letters[digit] for digit in digits]


def combinations(l1, l2):
    out_l = []
    for first_letter in l1:
        for second_letter in l2:
            out_l.append(first_letter + second_letter)
    return out_l


def phone_number_combinations(digits):
    letter_sets = get_letter_sets(digits)
    n = len(letter_sets)
    if n == 0:
        return []
    elif n == 1:
        return letter_sets[0]
    else:
        acc_l = letter_sets[0] 
        for i in range(1, len(letter_sets)):
            acc_l = combinations(acc_l, letter_sets[i])
        return acc_l


if __name__ == '__main__':
    import sys
    arg = sys.argv[1] if len(sys.argv) > 1 else ""
    try:
        for combination in phone_number_combinations(arg):
            print(combination)
    except KeyError as e:
        (digit,) = e.args
        print('invalid digit:', digit)
        sys.exit(1)
