#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * compute_factors - Find and print factors of a number
 * @target: The number to factorize
 *
 * This function finds the smallest factor of the target number
 * and prints the factorization.
 */
void compute_factors(long long int target)
{
	long int divisor;
	long long int quotient;

	for (divisor = 2; divisor <= sqrt(target); divisor++)
	{
		if (target % divisor == 0)
		{
			quotient = target / divisor;
			printf("%lld=%lld*%ld\n", target, quotient, divisor);
			return;
		}
	}
	printf("%lld=%lld*1\n", target, target);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *input_file;
	long long int current_number;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	input_file = fopen(argv[1], "r");
	if (!input_file)
	{
		perror("Error opening file");
		return (1);
	}

	while (fscanf(input_file, "%lld", &current_number) == 1)
	{
		compute_factors(current_number);
	}

	fclose(input_file);
	return (0);
}
