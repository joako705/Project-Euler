#find the sum of all the numbers that are equal to the sum of the factorial of their digits

import math

#for a number with x number of digits:
#max digit factorial: 9!
#max digit sum: 9! * x
#value of a number with x number of digits: 10^x
#apply the same search limit concept as with problem 30:
x = 1
while (math.factorial(9) * x) >= 10**(x-1):
    x += 1

search_limit = (math.factorial(9) * (x-1))
num_sum = 0
num = 3 #1 and 2 are not considered per the problem statement

while (num < search_limit):
    sum_digits = 0
    for digit in str(num):
        sum_digits += math.factorial(int(digit))
    
    if sum_digits == num:
        num_sum += num
    
    num += 1

print(f"The sum of all the numbers that are equal to the sum of the factorial of their digits: {num_sum}")