#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
    long long int target_number = 239809320265259;
    long int smaller_factor = 2;
    long int larger_factor;

    while (target_number % smaller_factor)
    {
        if (smaller_factor <= target_number)
        {
            smaller_factor++;
        }
        else
        {
            return (-1);
        }
    }

    larger_factor = target_number / smaller_factor;
    printf("%lld = %ld * %ld\n", target_number, larger_factor, smaller_factor);
    return (0);
}
