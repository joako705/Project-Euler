# Problem URL: https://projecteuler.net/problem=20
# ---------------------------------------------------------------------------------
# Find the sum of the digits in 100!

# python makes things too easy sometimes
from math import factorial

sum = 0

# convert the result to a string, iterate through ea
digits = str(factorial(100)) 
for digit in digits:
    sum += int(digit)

print(f"Sum of the digits in 100!: {sum}")