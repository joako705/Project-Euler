# Problem URL: https://projecteuler.net/problem=34
# ---------------------------------------------------------------------------------
# Find the sum of all the numbers that are equal to the sum of the factorial of their digits

from math import factorial

# for a number with n-digits:
# - max digit factorial: 9!
# - max digit factorial sum: 9! * n
# - max value of an n-digit number: 10^n

# apply the same search limit idea as with problem 30:
# find the point at which 10^n > (9! * n)
n = 1
while (factorial(9) * n) >= 10**(n-1): n += 1

search_limit = (factorial(9) * (n-1))
num_sum = 0
num = 3 # start at 3, since 1 and 2 are not considered by the problem

for num in range(1, search_limit):
    sum_digits = 0

    # calculate num's sum of digit factorials
    for digit in str(num):
        sum_digits += factorial(int(digit))
    
    # check if that sum is equal to the number itself
    if sum_digits == num: num_sum += num

print(f"Sum of all the numbers that are equal to the sum of the factorial of their digits: {num_sum}")