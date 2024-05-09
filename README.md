# MathHelperFunctions

## numBits

By bit shifting an unsigned long until its most significant bit is 1, the most significant non-zero bit can be determined.
This function operates at a constant speed no matter the input. This is accomplished by performing a form of binary search, checking which half of the total space of integers the given integer presides in.

## fastIntSqrt

This functions returns the greatest integer less than or equal to the square root of the input. `numBits(sqrt(n))` must be at most `(numBits(n) + 1) / 2` rounded up, as $\sqrt{n} = n^{\frac{1}{2}}$ This gives an upper bound to perform a binary search with.
The lower bound can be determined to be greater than half of the upper bound, or simply the `upperBound / 2`. This is because $2^{\frac{\log_2(n) - 1}{2}} \leq \sqrt{n} \leq 2^{\frac{\log_2(n) + 1}{2}}$.
Given that we are performing binary search on a space that scales linearly with the size of the square root, giving a time complexity of $O(\frac{1}{2}\log_2(n))$

## sqrt2

This returns an estimation of the square root of 2 using a recursive formula along with the error bounds of the estimation.
The error bounds are calculated by retrieving the next estimate, subtracting the requested estimate from it, and taking its absolute value.
A proof for the formula is attached. (I know I could've done it with matrices, I don't want to though)

## bitString

This sets a given boolean array to be equal the binary representation of an unsigned long where the 0th index is the least signficant bit and the 63rd index is the most signficant.
The function is $O(log_2(n))$ as it simply reads the bits of the number out.

# exp

This returns the $b^e$ where $e$ is an unsigned long. This is performed in constant time.
