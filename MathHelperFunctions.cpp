#include <iostream>
#include <math.h>

// returns two doubles: an estimation of sqrt(2) and its error bounds
double* sqrt2(int x) {
    long n[] = {1, 3};
    long d[] = {1, 2};
    for (int i = 0; i < x; i++) {
        n[i % 2] += 2 * n[(i + 1) % 2];
        d[i % 2] += 2 * d[(i + 1) % 2];
    }
    double estimate = (double) n[x % 2] / (double) d[x % 2];
    return new double[2]{estimate, fabs((double) n[(x + 1) % 2] / (double) d[(x + 1) % 2] - estimate)};
}

signed char getNumBits(unsigned long n) {
    signed char x = 0;
    if (n == 0) {
        return x;
    }
    unsigned long compare = 1u;
    for (unsigned int i = 32; i > 0; i /= 2) {
        compare = (compare << i) - 1;
        if (n <= compare) {
            x += i;
            n <<= i;
        }
    }
    return 64 - x;
}

unsigned long fastIntSqrt(unsigned long n) {
    unsigned long max = (getNumBits(n) + 1) / 2;
    unsigned long min = 1 << max - 1;
    max = 1 << max;
    unsigned long x = (max + min) / 2;
    unsigned long sq = x * x;
    while(max > min && sq != n) {
        if (sq > n) {
            max = x - 1;
            x = (max + min) / 2;
            sq = x * x;
        }
        else if (sq < n) {
            min = x + 1;
            x = (max + min) / 2;
            sq = x * x;
        }
    }
    return x;
}

int main() {
    printf("%.32f, %.32f\n", sqrt2(10)[0], sqrt2(10)[1]);
    printf("%.32f, %.32f\n", sqrt2(20)[0], sqrt2(20)[1]);
    printf("%.32f, %.32f\n", sqrt2(30)[0], sqrt2(30)[1]);

    return 0;
}
