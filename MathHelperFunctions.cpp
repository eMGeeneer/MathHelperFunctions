// returns the absolute value of a double
double abs(int x) {
    return x >= 0 ? x : -x;
}

// returns two doubles: an estimation of sqrt(2) and its error bounds
// this uses a recursive math function similar to the Fibonacci sequence to estimate
// the numerator and denominator follow the same formula but have different starting values
double sqrt2(int x, double* error) {
    long n[] = {1, 3}; // the starting values of the numerator
    long d[] = {1, 2}; // starting values of the denominator
    for (int i = 0; i < x; i++) {
        n[i % 2] += 2 * n[(i + 1) % 2]; // how each subsequent value is defined
        d[i % 2] += 2 * d[(i + 1) % 2];
    }
    double estimate = (double) n[x % 2] / (double) d[x % 2];
    double err = abs((double) n[(x + 1) % 2] / (double) d[(x + 1) % 2] - estimate)
    error = &err;
    return estimate;
}

// returns the number of bits occupied by a given unsigned long as a signed byte
char numBits(unsigned long n) {
    if (n < 3) {
        return n;
    }
    char x = 0;
    unsigned long compare = 0;
    for (char i = 32; i > 0; i /= 2) {
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

// sets the given array to be equal to the base 12 representation of the given unsigned long where the 0th index is the least significant digit and the 5th index is the most
// also returns the position of the most significant digit
char dozenal(char dozen[6], unsigned long n) {
    char i = 0;
    while (n > 0) {
        dozen[i] = n % 12;
        i++;
        n /= 12;
    }
    return i - 1;
}

long exp(long b, unsigned long e) {
    if (e < 2) {
        return e == 1 ? b : 1;
    }
    long result;
    char dozen[6];
    char n = dozenal(dozen, e);
    switch (dozen[n]) {
    case 1:
        result = b;
        break;
    case 2:
        result = b * b;
        break;
    case 3:
        result = b * b * b;
        break;
    case 4:
        result = b * b;
        result *= result;
        break;
    case 5:
        result = b * b;
        result *= result * b;
        break;
    case 6:
        result = b * b * b;
        result *= result;
        break;
    case 7:
        result = b * b * b;
        result *= result * b;
        break;
    case 8:
        result = b * b;
        result *= result;
        result *= result;
        break;
    case 9:
        result = b * b;
        result *= result;
        result *= result * b;
        break;
    case 10:
        result = b * b;
        result *= result * b;
        result *= result;
        break;
    default:
        result = b * b;
        result *= result * b;
        result *= result * b;
    }
    for (char i = n - 1; i >= 0; i--) {
        switch (dozen[i]) {
        case 0:
            result *= result * result;
            result *= result;
            result *= result;
            break;
        case 1:
            result *= result * result;
            result *= result;
            result *= result * b;
            break;
        case 2:
            result *= result * result;
            result *= result * b;
            result *= result;
            break;
        case 3:
            result *= result;
            result *= result * b;
            result *= result * result;
            break;
        case 4:
            result *= result * result * b;
            result *= result;
            result *= result;
            break;
        case 5:
            result *= result * result * b;
            result *= result;
            result *= result * b;
            break;
        case 6:
            result *= result * b;
            result *= result;
            result *= result * result;
            break;
        case 7:
            result *= result * b;
            result *= result;
            result *= result * result * b;
            break;
        case 8:
            result *= result * result * b * b;
            result *= result;
            result *= result;
            break;
        case 9:
            result *= result * result * b * b;
            result *= result;
            result *= result * b;
            break;
        case 10:
            result *= result * result * b * b;
            result *= result * b;
            result *= result;
            break;
        default:
            result *= result * result * b * b;
            result *= result * b;
            result *= result * b;
        }
    }
    return result;
}

int main() {
    return 0;
}
