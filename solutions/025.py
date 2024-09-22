# Problem URL: https://projecteuler.net/problem=25
# ---------------------------------------------------------------------------------
# Find the index of the first term in the Fibonacci sequence to have 1000 digits

from math import floor, log10

fib_nums = [1, 1] # per the problem's explanation, the first number of the sequence is considered to be 1

# formula for quickly calculating digits: floor(log(x) + 1)
# this loop keeps calculating Fibonacci numbers as long as the most recently added one has less than 1000 digits
while (floor(log10(fib_nums[-1])) + 1) < 1000:
    fib_nums.append(fib_nums[-1] + fib_nums[-2])

# just printing the length of the list, since the problem considers the Fibonacci sequence to be indexed from 1
print(f"Index of the first term of the Fibonacci sequence to have 1000 digits: {len(fib_nums)}")