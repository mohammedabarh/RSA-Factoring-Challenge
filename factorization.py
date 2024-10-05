#!/usr/bin/python3
import sys


def find_two_factors(target):
    """Generate two factors for a given number"""
    divisor = 2
    while (target % divisor):
        if (divisor <= target):
            divisor += 1

    quotient = target // divisor
    return (quotient, divisor)


if len(sys.argv) != 2:
    sys.exit(f"Incorrect usage: {sys.argv[0]} <input_file_path>")

input_file_path = sys.argv[1]

with open(input_file_path, 'r') as file:
    content = file.readlines()

for line in content:
    number = int(line.strip())
    factor1, factor2 = find_two_factors(number)
    print(f"{number} = {factor1} * {factor2}")
