# Problem URL: https://projecteuler.net/problem=20
# --------------------------------------------------------
# Find the sum of the digits in 100!

import math

sum = 0
digits = str(math.factorial(100))

for digit in digits:
    sum += int(digit)

print(f"Sum of the digits in 100!: {sum}")