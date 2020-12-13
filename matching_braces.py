def braces_match(expr_str):
    n_paren_pairs = 0
    n_square_pairs = 0
    n_brace_pairs = 0
    for char in expr_str:

        if char == '(':
            n_paren_pairs += 1
        elif char == ')':
            n_paren_pairs -= 1

        elif char == '[':
            n_square_pairs += 1
        elif char == ']':
            n_square_pairs -= 1

        elif char == '{':
            n_brace_pairs += 1
        elif char == '}':
            n_brace_pairs -= 1
    return all(n == 0 for n in (n_paren_pairs, n_square_pairs, n_brace_pairs))


if __name__ == '__main__':
    import sys
    arg = sys.argv[1] if len(sys.argv) > 1 else ""
    print(braces_match(arg))
