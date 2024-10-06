#!/usr/bin/python3
"""Efficient Factorization Module"""
import sys
from math import isqrt


def compute_factors(target):
    """
    Compute two factors for a given number
    """
    for potential_factor in range(2, isqrt(target) + 1):
        if target % potential_factor == 0:
            return target // potential_factor, potential_factor
    return target, 1


if len(sys.argv) != 2:
    sys.exit(f"Usage: {sys.argv[0]} <file_path>")

input_file_path = sys.argv[1]

with open(input_file_path, 'r') as input_file:
    for line in input_file:
        current_number = int(line.strip())
        large_factor, small_factor = compute_factors(current_number)
        print(f"{current_number} = {large_factor} * {small_factor}")
