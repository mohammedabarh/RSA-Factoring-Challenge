#!/usr/bin/python3
"""Module for factorizing numbers from a file"""
import sys


def find_factors(target):
    """
    Generate two factors for a given number.

    Args:
        target (int): Number to factorize.

    Returns:
        tuple: A pair of factors (larger_factor, smaller_factor).
    """
    smaller_factor = 2
    while target % smaller_factor:
        if smaller_factor <= target:
            smaller_factor += 1

    larger_factor = target // smaller_factor
    return (larger_factor, smaller_factor)


def main():
    """Main function to process the input file and factorize numbers."""
    if len(sys.argv) != 2:
        sys.exit(f"Usage: {sys.argv[0]} <file_path>")

    input_file = sys.argv[1]

    try:
        with open(input_file, 'r') as file:
            for line in file:
                number = int(line.strip())
                larger, smaller = find_factors(number)
                print(f"{number} = {larger} * {smaller}")
    except FileNotFoundError:
        sys.exit(f"Error: File '{input_file}' not found.")
    except ValueError:
        sys.exit("Error: Invalid number in the input file.")


if __name__ == "__main__":
    main()
