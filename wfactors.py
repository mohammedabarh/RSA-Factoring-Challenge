#!/usr/bin/python3
import sys
from math import isqrt

def compute_factors(value):
    """Generate two factors for the given number."""
    for candidate in range(2, isqrt(value) + 1):
        if value % candidate == 0:
            return (value // candidate, candidate)
    return (1, value)  # If prime, return 1 and the number itself

if len(sys.argv) != 2:
    sys.exit(f"Wrong usage: {sys.argv[0]} <file_path>")

file_path = sys.argv[1]

with open(file_path, 'r') as file:
    lines = file.readlines()

for line in lines:
    num = int(line.strip())
    factor2, factor1 = compute_factors(num)
    print(f"{num} = {factor2} * {factor1}")
