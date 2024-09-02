# Problem URL: https://projecteuler.net/problem=34
# ----------------------------------------------------------------------------------------------------
# Find the sum of all the numbers that are equal to the sum of the factorial of their digits

from math import factorial

# for a number with n number of digits:
# - max digit factorial: 9!
# - max digit sum: 9! * n
# - value of a number with n number of digits: 10^n

# apply the same search limit idea as with problem 30:
n = 1
while (factorial(9) * n) >= 10**(n-1): n += 1

search_limit = (factorial(9) * (n-1))
num_sum = 0
num = 3 #1 and 2 are not considered per the problem statement

while (num < search_limit):
    sum_digits = 0
    for digit in str(num):
        sum_digits += factorial(int(digit))
    
    if sum_digits == num:
        num_sum += num
    
    num += 1

print(f"Sum of all the numbers that are equal to the sum of the factorial of their digits: {num_sum}")