#find the sum of the digits in 100!

import math

sum = 0
digits = str(math.factorial(100))

for char in digits:
    sum += int(char)

print(sum)