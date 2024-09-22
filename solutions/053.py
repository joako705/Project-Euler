# Problem URL: https://projecteuler.net/problem=53
# ---------------------------------------------------------------------------------
# In combinatorics, nCr ("from n choose r") = n! / (r! * (n-r)!), where r <= n
# ---------------------------------------------------------------------------------
# For 1 <= n <= 100, how many values of nCr are greater than 1,000,000?

from math import factorial

# implement the formula for nCr
def nCr(n, r):
    return factorial(n) / (factorial(r) * factorial(n - r))

# check all combinations of n and r from 1 to 100, and count the times nCr exceeds 1 million
total = 0
for n in range(1, 101):
    for r in range(1, n+1):
        if nCr(n, r) > 10**6: total += 1

print(f"Values of nCr over 1 million: {total}")