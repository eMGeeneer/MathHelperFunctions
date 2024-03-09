# MathHelperFunctions

## getNumBits

By bit shifting an unsigned long until its most significant bit is 1, most significant non-zero bit can be determined.
We can check if the most significant non-zero bit is at the half-way point each time. This way, the function can operate at $O(\log(b))$ where b is the number of bits.
The number of bits increases logarithmically with the value of the long, so this function returns in $O(\log(\log(n)))$

## fastIntSqrt

getNumBits(sqrt(n)) must be at most getNumBits(n) / 2 rounded up, as $\sqrt{n} = n^{\frac{1}{2}}$ This gives an upper bound to perform a binary search with.
The lower bound can be determined to be greater than half of the upper bound, or simply the upper bound >> 1. This is because $2^{\lceil\frac{\log_2(n)}{2}\rceil -1} \leq \sqrt{n} \leq 2^{\lceil\frac{\log_2(n)}{2}\rceil}$
. Given that we are performing binary search on a space that scales linearly with the size of the square root, giving a time complexity of $O(\frac{1}{2}\log_2(n))$

## sqrt2

This returns an estimation of the square root of 2 using a recursive formula along with the error bounds of the estimation.
The error bounds are calculated by retrieving the next estimate, subtracting the requested estimate from it, and taking its absolute value.
A proof for the formula follows.
$N_n = 2N_{n - 1} + N_{n - 2} \quad N_0 = 1 \quad N_1 = 3 \\ f(x) = \sum^\infty_{n = 0}N_nx^n \\ = 1 + \sum^\infty_{n = 1}N_nx^n \\ $
= 1 + 3x + \sum^\infty_{n = 2}N_nx^n \\ 
= 1 + 3x + \sum^\infty_{n = 2}(2N_{n - 1} + N_{n - 2})x^n \\ 
= 1 + 3x + \sum^\infty_{n = 2}2N_{n - 1}x^n + \sum^\infty_{n = 2}N_{n - 2}x^n \\ 
\sum^\infty_{n = 2}2N_{n - 1}x^n = x\sum^\infty_{n = 2}N_{n - 1}x^{n - 1} \\
= 2x\sum^\infty_{n = 1}N_nx^n \\
= 2x(f(x) - 1) \\
\sum^\infty_{n = 2}N_{n - 2}x^n = x^2\sum^\infty_{n = 2}N_{n - 2}x^{n -2} \\
= x^2\sum^\infty_{n = 0}x^n \\
= x^2f(x) \\
f(x) = 1 + 3x + 2x(f(x) - 1) + x^2f(x) \\
= 1 + x + 2xf(x) + x^2f(x) \\
f(x) - 2xf(x) - x^2f(x) = x + 1 \\
1 - 2x - x^2 = \frac{x + 1}{f(x)} \\
-\frac{x^2 + 2x - 1}{x + 1} = \frac{1}{f(x)} \\
f(x) = -\frac{x + 1}{x^2 + 2x - 1} \\
= -\frac{x + 1}{(x + 1 + \sqrt{2})(x + 1 - \sqrt{2})} \\
= \frac{A}{x + 1 + \sqrt{2}} + \frac{B}{x + 1 - \sqrt{2}} \\
-x - 1 = A(x + 1 - \sqrt{2}) + B(x + 1 + \sqrt{2}) \\
(1 - \sqrt{2})A + (1 + \sqrt{2})B = -1 \\
Ax + Bx = -x \\
A = -\frac{1}{2} \\
B = -\frac{1}{2} \\
f(x) = -\frac{1}{2}(\frac{1}{x + 1 + \sqrt{2}} + \frac{1}{x + 1 - \sqrt{2}}) \\
\frac{1}{x + 1 + \sqrt{2}} = \frac{1}{(1 + \sqrt{2})(\frac{x}{1 + \sqrt{2}} + 1)} \\
= (\sqrt{2}-1)\sum^\infty_{n = 0}(\frac{-x}{1 + \sqrt{2}})^n \\
= (\sqrt{2}-1)\sum^\infty_{n = 0}(1 - \sqrt{2})^nx^n \\
\frac{1}{2(x + 1 - \sqrt{2})} = \frac{1}{(1 - \sqrt{2})(\frac{x}{1 - \sqrt{2}} + 1)} \\
= -(\sqrt{2} + 1)\sum^\infty_{n = 0}(\frac{-x}{1 - \sqrt{2}})^n \\
= -(\sqrt{2} + 1)\sum^\infty_{n = 0}((1 + \sqrt{2})^nx^n) \\
f(x) = -\frac{1}{2}((\sqrt{2} - 1)\sum^\infty_{n = 0}(1 - \sqrt{2})^nx^n - (\sqrt{2} + 1)\sum^\infty_{n = 0}((1 + \sqrt{2})^nx^n)) \\
f(x) = \sum^\infty_{n = 0} -\frac{1}{2}((\sqrt{2} - 1)(1 - \sqrt{2})^n - (\sqrt{2} + 1)(1 + \sqrt{2})^n)x^n \\
N_n = \frac{1}{2}((1 - \sqrt{2})^{n + 1} + (1 + \sqrt{2})^{n + 1}) \\
\\
D_n = 2D_{n - 1} + D_{n - 2} \quad D_0 = 1 \quad D_1 = 2 \\
g(x) = \sum^\infty_{n = 0}D_nx^n \\
= 1 + \sum^\infty_{n = 1}D_nx^n \\
= 1 + 2x + \sum^\infty_{n = 2}D_nx^n \\
= 1 + 2x + \sum^\infty_{n = 2}(2D_{n - 1} + D_{n - 2})x^n \\
= 1 + 2x + \sum^\infty_{n = 2}2D_{n - 1}x^n + \sum^\infty_{n = 2}D_{n - 2}x^n \\
\sum^\infty_{n = 2}2D_{n - 1}x^n = x\sum^\infty_{n = 2}D_{n - 1}x^{n - 1} \\
= 2x\sum^\infty_{n = 1}D_nx^n \\
= 2x(g(x) - 1) \\
\sum^\infty_{n = 2}D_{n - 2}x^n = x^2\sum^\infty_{n = 2}D_{n - 2}x^{n -2} \\
= x^2\sum^\infty_{n = 0}x^n \\
= x^2g(x) \\
g(x) = 1 + 2x + 2x(g(x) - 1) + x^2g(x) \\
= 1 + 2xg(x) + x^2g(x) \\
g(x) - 2xg(x) - x^2g(x) = 1 \\
1 - 2x - x^2 = \frac{1}{g(x)} \\
g(x) = -\frac{1}{x^2 + 2x - 1} \\
= -\frac{1}{(x + 1 + \sqrt{2})(x + 1 - \sqrt{2})} \\
= \frac{C}{x + 1 + \sqrt{2}} + \frac{D}{x + 1 - \sqrt{2}} \\
-1 = C(x + 1 - \sqrt{2}) + D(x + 1 + \sqrt{2}) \\
(1 - \sqrt{2})C + (1 + \sqrt{2})D = -1 \\
C + D = 0 \\
C = \frac{\sqrt{2}}{4} \\
D = -\frac{\sqrt{2}}{4} \\
g(x) = \frac{\sqrt{2}}{4}(\frac{1}{x + 1 + \sqrt{2}} - \frac{1}{x + 1 - \sqrt{2}}) \\
\frac{1}{x + 1 + \sqrt{2}} = \frac{1}{(1 + \sqrt{2})(\frac{x}{1 + \sqrt{2}} + 1)} \\
= (\sqrt{2}-1)\sum^\infty_{n = 0}(\frac{-x}{1 + \sqrt{2}})^n \\
= (\sqrt{2}-1)\sum^\infty_{n = 0}(1 - \sqrt{2})^nx^n \\
\frac{1}{2(x + 1 - \sqrt{2})} = \frac{1}{(1 - \sqrt{2})(\frac{x}{1 - \sqrt{2}} + 1)} \\
= -(\sqrt{2} + 1)\sum^\infty_{n = 0}(\frac{-x}{1 - \sqrt{2}})^n \\
= -(\sqrt{2} + 1)\sum^\infty_{n = 0}((1 + \sqrt{2})^nx^n) \\
g(x) = \frac{\sqrt{2}}{4}((\sqrt{2} - 1)\sum^\infty_{n = 0}(1 - \sqrt{2})^nx^n + (\sqrt{2} + 1)\sum^\infty_{n = 0}((1 + \sqrt{2})^nx^n)) \\
g(x) = \sum^\infty_{n = 0} \frac{\sqrt{2}}{4}((\sqrt{2} - 1)(1 - \sqrt{2})^n + (\sqrt{2} + 1)(1 + \sqrt{2})^n)x^n \\
D_n = -\frac{\sqrt{2}}{4}((1 - \sqrt{2})^{n + 1} - (1 + \sqrt{2})^{n + 1}) \\
\\
\lim_{n \rightarrow \infty}\frac{N_n}{D_n} = \lim_{n \rightarrow \infty}\frac{\frac{1}{2}((1 - \sqrt{2})^{n + 1} + (1 + \sqrt{2})^{n + 1})}{-\frac{\sqrt{2}}{4}((1 - \sqrt{2})^{n + 1} - (1 + \sqrt{2})^{n + 1})} \\
|1 - \sqrt{2}| < 1 \\
\lim_{n \rightarrow \infty}(\pm(1 - \sqrt{2}))^n = 0 \\
\lim_{n \rightarrow \infty}\frac{N_n}{D_n} = \lim_{n \rightarrow \infty}\frac{\frac{1}{2}(0 + (1 + \sqrt{2})^{n + 1})}{-\frac{\sqrt{2}}{4}(0 - (1 + \sqrt{2})^{n + 1})} \\
= \lim_{n \rightarrow \infty}\frac{\frac{1}{2}(1 + \sqrt{2})^{n + 1}}{\frac{\sqrt{2}}{4}(1 + \sqrt{2})^{n + 1}} \\
= \lim_{n \rightarrow \infty}\frac{\frac{1}{2}}{\frac{\sqrt{2}}{4}} \\
= \frac{1}{2} \times \frac{4}{\sqrt{2}} \\
= \frac{1}{2} \times \frac{4\sqrt{2}}{2} \\
= \frac{2\sqrt{2}}{2} \\
= \sqrt{2} \\$
