#include "factors.h"

int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void rsa_factorize(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, file)) != -1) {
        long long n = atoll(line);
        if (n > 1) {
            long long i;
            for (i = 2; i <= sqrt(n); i++) {
                if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
                    printf("%lld=%lld*%lld\n", n, n / i, i);
                    break;
                }
            }
            if (i > sqrt(n)) {
                printf("%lld=%lld*1\n", n, n);
            }
        }
    }

    free(line);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    rsa_factorize(argv[1]);
    return 0;
}
