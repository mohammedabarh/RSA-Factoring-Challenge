#!/usr/bin/python3

### 2. `factors.py`
This is the main Python script that performs the factorization.

```python
import sys
import math

def read_numbers_from_file(file_path):
    """Reads a list of natural numbers from a file."""
    with open(file_path, 'r') as file:
        numbers = [int(line.strip()) for line in file]
    return numbers

def trial_division(n):
    """Basic factorization using trial division."""
    for i in range(2, int(math.isqrt(n)) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1  # If n is prime or can't be factored

def factorize_file(file_path):
    """Reads numbers from a file and factorizes each one."""
    numbers = read_numbers_from_file(file_path)
    for number in numbers:
        p, q = trial_division(number)
        print(f"{number}={p}*{q}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 factors.py <file>")
        sys.exit(1)

    input_file = sys.argv[1]
    factorize_file(input_file)

