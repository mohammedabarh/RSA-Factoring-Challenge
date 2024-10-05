#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    long long int number;
    // Read the number from input
    scanf("%lld", &number);
    long long int factor1, factor2;

    // Loop to find factors of the number
    for (factor1 = 2; factor1 <= sqrt(number); factor1++) {
        if (number % factor1 == 0) {
            factor2 = number / factor1;
            printf("%lld = %lld * %lld\n", number, factor2, factor1);
            return 0;
        }
    }
    // If no factors found, print the number as a product of 1 and itself
    printf("%lld = 1 * %lld\n", number, number);
    return 0;
}
