#include <iostream>
#include <stdio.h>
#include <math.h>

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

int main() {
    printf("%.32f, %.32f\n", sqrt2(10)[0], sqrt2(10)[1]);
    printf("%.32f, %.32f\n", sqrt2(20)[0], sqrt2(20)[1]);
    printf("%.32f, %.32f\n", sqrt2(30)[0], sqrt2(30)[1]);

    return 0;
}
