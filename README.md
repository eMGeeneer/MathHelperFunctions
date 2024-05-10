# MathHelperFunctions

## numBits

By bit shifting an unsigned long until its most significant bit is 1, the most significant non-zero bit can be determined.
This function operates at a constant speed no matter the input. This is accomplished by performing a form of binary search, checking which half of the total space of integers the given integer presides in.

## fastIntSqrt

This functions returns the greatest integer less than or equal to the square root of the input. `numBits(sqrt(n))` must be at most `(numBits(n) + 1) / 2`, as $\sqrt{n} = n^{\frac{1}{2}}$ This gives an upper bound to perform a binary search with.
The lower bound can be determined to be greater than half of the upper bound, or simply the `upperBound / 2`. This is because $2^{\frac{\log_2(n) - 1}{2}} \leq \sqrt{n} \leq 2^{\frac{\log_2(n) + 1}{2}}$.
Given that we are performing binary search on a space that scales linearly with the size of the square root, the function has a time complexity of $O(\frac{1}{2}\log_2(n))$.

## fastIntCbrt

This functions returns the greatest integer less than or equal to the square root of the input. `numBits(cbrt(n))` must be at most `(numBits(n) + 2) / 3`, as $\sqrt[3]{n} = n^{\frac{1}{3}}$ This gives an upper bound to perform a binary search with.
The lower bound can be determined to be greater than half of the upper bound, or simply the `upperBound / 4`. This is because $2^{\frac{\log_2(n)}{3} - 2} \leq \sqrt[3]{n} \leq 2^{\frac{\log_2(n + 2)}{3}}$.
Given that we are performing binary search on a space that scales linearly with the size of the cuberoot, the function has a time complexity of $O(\frac{1}{3}\log_2(n))$.

## fastIntNthRoot

This functions returns the greatest integer less than or equal to the square root of the input. `numBits(nthRoot(x))` must be at most `(numBits(x) + n - 1) / n`, as $\sqrt[n]{x} = x^{\frac{1}{n}}$ This gives an upper bound to perform a binary search with.
The lower bound can be determined to be greater than half of the upper bound, or simply the `upperBound / (1 << numBits - 1)`. This is because $2^{\frac{\log_2(x)}{n} - n} \leq \sqrt[n]{x} \leq 2^{\frac{\log_2(x) + n - 1}{n}}$.
The power uses `exp()` which is performed in $O(\log_{12}(n))$ time.
Given that we are performing binary search on a space that scales linearly with the size of the nth root and each binary search requires another `exp()` call, these time complexities are multiplied together.
$\frac{1}{n}\log_{12}(2^{\frac{\log_2(x) + n + 1}{n}}) = \frac{1}{n}\frac{\log_2(x) + n + 1}{n\log_2(12)})$.
The time complexity is $O(\frac{\log_2(x)}{n\log_2(12)})$.

## sqrt2

This returns an estimation of the square root of 2 using a recursive formula along with the error bounds of the estimation.
The error bounds are calculated by retrieving the next estimate, subtracting the requested estimate from it, and taking its absolute value.
A proof for the formula is attached. (I know I could've done it with matrices, I don't want to though)

## dozenal

This sets a given `char` array to be equal the quaternary representation of an unsigned long where the 0th index is the least signficant digit and the 5th index is the most signficant.
The function is $O(\log_{12}(n))$ as it simply reads the bits of the number out.
It also returns the position of the most significant digit.

# exp

This returns the $b^e$ where $e$ is an unsigned long. This is performed $O(\log_{12}(n))$ as it is based on the position of the most significant bit given by `quaternary()`.
By reading in the base 12 representation of the exponent backwards starting from the 0 one position of significance below the most significant non-zero digit. The number is divided by 12 each iteration and a number $n$ is added if that number is read out from the base 12 representation. This can be represented by raising the `accumulator` to the power of 12 as $b^{12} = b \cdot b \cdot b \cdot b \dots b$. Then adding $n$ can be represented by multiplying the `accumulator` by the given base as $b^{x + n} = b^x \cdot b^n$.
Base 12 was chosen through running multiple trials of different bases until the most optimal base was found.
