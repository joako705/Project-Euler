#find the index of the first term in the Fibonacci sequence to have 1000 digits

import math

fib_nums = [1, 1]

while (math.floor(math.log10(fib_nums[-1])) + 1) < 1000:
    fib_nums.append(fib_nums[-1] + fib_nums[-2])

print(len(fib_nums))
print(fib_nums[-1])