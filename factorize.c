#include "factors.h"

void factorize_number(long long n) {
    long long i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf("%lld=%lld*%lld\n", n, n / i, i);
            return;
        }
    }
    printf("%lld=%lld*1\n", n, n);
}
