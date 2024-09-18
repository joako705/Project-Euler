# Problem URL: https://projecteuler.net/problem=25
# -------------------------------------------------------------------------------------------
# Find the index of the first term in the Fibonacci sequence to have 1000 digits

from math import floor, log10

fib_nums = [1, 1]

while (floor(log10(fib_nums[-1])) + 1) < 1000:
    fib_nums.append(fib_nums[-1] + fib_nums[-2])

print(f"Index of the first term of the Fibonacci sequence to have 1000 digits: {len(fib_nums)}")