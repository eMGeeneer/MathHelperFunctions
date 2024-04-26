#include <math.h>

// returns two doubles: an estimation of sqrt(2) and its error bounds
// this uses a recursive math function similar to the Fibonacci sequence to estimate
// it has a numerator and a denominator
double* sqrt2(int x) {
    long n[] = {1, 3}; // the starting values of the numerator
    long d[] = {1, 2}; // starting values of the denominator
    for (int i = 0; i < x; i++) {
        n[i % 2] += 2 * n[(i + 1) % 2]; // how each subsequent value is defined
        d[i % 2] += 2 * d[(i + 1) % 2];
    }
    double estimate = (double) n[x % 2] / (double) d[x % 2];
    return new double[2]{estimate, fabs((double) n[(x + 1) % 2] / (double) d[(x + 1) % 2] - estimate)};
}

// returns the number of bits occupied by a given unsigned long as a signed byte
signed char numBits(unsigned long n) {
    if (n < 3) {
        return n;
    }
    signed char x = 0;
    unsigned long compare = 0;
    for (unsigned int i = 32; i > 0; i /= 2) {
        compare = (compare + 1 << i) - 1; // cut the space to check in half each time
        if (n <= compare) {
            x += i;
            n <<= i;
        }
    }
    return 64 - x;
}

// returns the greatest unsigned long less than a given unsigned long's square root 
// uses binary search
unsigned long fastIntSqrt(unsigned long n) {
    if (n < 2) {
        return n;
    }
    unsigned long max = (numBits(n) + 1) / 2;
    unsigned long min = 1 << max - 1;
    max = (1 << max) - 1;
    unsigned long x = (max + min) / 2;
    unsigned long sq = x * x;
    while(max > min && sq != n) {
        if (sq > n) {
            max = x - 1;
        }
        else if (sq < n) {
            min = x + 1;
        }
        x = (max + min) / 2; 
        sq = x * x;
    }
    if (sq > n) {
        x--;
    }
    return x;
}

int main() {
    return 0;
}
