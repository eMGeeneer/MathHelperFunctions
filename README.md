# MathHelperFunctions

## getNumBits

By bit shifting an unsigned long until its most significant bit is 1, most significant non-zero bit can be determined.
We can check if the most significant non-zero bit is at the half-way point each time. This way, the function can operate at $O(\log_2(b))$ where b is the number of bits.
The number of bits increases logarithmically with the value of the long, so this function returns in $O(\log_2(\log_2(n)))$

## fastIntSqrt

getNumBits(sqrt(n)) must be at most getNumBits(n) / 2 rounded up, as $\sqrt{n} = n^{\frac{1}{2}}$ This gives an upper bound to perform a binary search with.
The lower bound can be determined to be greater than half of the upper bound, or simply the upper bound >> 1. This is because $2^{\lceil\frac{\log_2(n)}{2}\rceil -1} \leq \sqrt{n} \leq 2^{\lceil\frac{\log_2(n)}{2}\rceil}$
. Given that we are performing binary search on a space that scales linearly with the size of the square root, giving a time complexity of $O(\frac{1}{2}\log_2(n))$

## sqrt2

This returns an estimation of the square root of 2 using a recursive formula along with the error bounds of the estimation.
The error bounds are calculated by retrieving the next estimate, subtracting the requested estimate from it, and taking its absolute value.
A proof for the formula is attached.
