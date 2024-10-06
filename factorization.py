#!/usr/bin/python3
"""Module for RSA factorization"""
from sys import argv


def factorize_rsa(file_path):
    """
    Factorize numbers from a file using RSA algorithm.

    Args:
        file_path (str): Path to the input file.
    """
    with open(file_path) as input_file:
        for line in input_file:
            number = int(line)
            print(f"{number:d}=", end="")
            if number % 2 == 0:
                print(f"{number//2}*2")
                continue
            for divisor in range(3, number, 2):
                if number % divisor == 0:
                    quotient = number // divisor
                    for potential_factor in range(3, quotient, 2):
                        if quotient % potential_factor == 0 or divisor % potential_factor == 0:
                            break
                    print(f"{quotient}*{divisor}")
                    break


if __name__ == "__main__":
    if len(argv) == 2:
        factorize_rsa(argv[1])
