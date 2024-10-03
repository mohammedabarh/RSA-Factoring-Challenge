#!/usr/bin/env python3

import sys
from math import sqrt

def factorize(n):
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return i, n // i
    return None

def main(filename):
    with open(filename, 'r') as file:
        for line in file:
            n = int(line.strip())
            factors = factorize(n)
            if factors:
                print(f"{n}={factors[1]}*{factors[0]}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)
    main(sys.argv[1])
