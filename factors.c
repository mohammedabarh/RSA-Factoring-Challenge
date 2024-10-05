#include <stdio.h>

int main()
{
    long long int target_number = 239809320265259;
    long int divisor = 2;
    long int quotient;

    while (target_number % divisor)
    {
        if (divisor <= target_number)
        {
            divisor++;
        }
        else {
            return (-1);
        }
    }

    quotient = target_number / divisor;
    printf("%lld = %ld * %ld\n", target_number, quotient, divisor);
    return (0);
}
