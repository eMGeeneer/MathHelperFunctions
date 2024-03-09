# MathHelperFunctions

## getNumBits

By bit shifting an unsigned long until its most significant bit is 1, most significant non-zero bit can be determined.
We can check if the most significant non-zero bit is at the half-way point each time. This way, the function can operate at $O(\log(b))$ where $b$ is the number of bits.
The number of bits increases logarithmically with the value of the long, so this function returns in $O(\log(\log(n)))$
