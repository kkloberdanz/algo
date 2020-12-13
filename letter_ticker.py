def _next_letter(letter):
    return chr(((ord(letter) - ord('a') + 1) % 26) + ord('a'))


class WordTicker:
    def __init__(self, start='a', end='z', next_letter_func=_next_letter):
        self.letters = []
        self._next_letter_func = next_letter_func
        self.start = start
        self.end = end

    def __next__(self):
        i = 0
        nletters = len(self.letters)
        if nletters == 0:
            self.letters = [self.start]
            return self

        has_grown = False
        while self.letters[i] == self.end:
            self.letters[i] = self._next_letter_func(self.letters[i])
            i += 1
            if i >= nletters:
                self.letters.append(self.start)
                has_grown = True
                break
        if not has_grown:
            self.letters[i] = self._next_letter_func(self.letters[i])
        return self


    def __iter__(self):
        return self


    def __repr__(self):
        return ''.join(reversed(self.letters))


if __name__ == '__main__':
    import sys

    ticker = WordTicker()
    for word in ticker:
        try:
            print(word)
        except BrokenPipeError:
            # this is triggered when a UNIX pipeline is complete, meaning
            # this is a successful exit condition
            sys.exit(0)
