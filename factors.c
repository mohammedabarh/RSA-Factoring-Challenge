#!/usr/bin/env python3

def factorize(n):
    """Returns two factors of n."""
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1  # In case n is prime, which won't happen in this context

def main(filename):
    with open(filename, 'r') as f:
        for line in f:
            n = int(line.strip())
            p, q = factorize(n)
            print(f"{n}={p}*{q}")

if __name__ == "__main__":
    import sys
    main(sys.argv[1])
