# Problem URL: https://projecteuler.net/problem=20
# ---------------------------------------------------------------------------------
# Find the sum of the digits in 100!

from math import factorial

result = 0

# convert the result to a string, iterate through each digit and add it to the sum
digits = str(factorial(100)) 
for digit in digits:
    result += int(digit)

print(f"Sum of the digits in 100!: {result}")