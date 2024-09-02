# Problem URL: https://projecteuler.net/problem=30
# -----------------------------------------------------------------------------------------------------------
# Find the sum of all the numbers that can be written as the sum of the fifth power of their digits

# first, need to figure out when to stop checking numbers and their digits:
# for digits 1-9, the max any digit raised to the fifth can equal is 9^5
# therefore, for a number with n digits, the absolute maximum the sum of its digits' fifth powers can be is (9^5)*n
# however, the value of an n-digit number increases exponentionally as n increases (10^n)
# so eventually, there'll be an n-digit number that CAN'T be written as the sum of the fifths of its digits, because that would be smaller than the number itself. 
# so to find the max number of digits that need to be checked, just keep incrementing n_digits until 10^(n_digits-1) is greater than (9^5)*n_digits

n_digits = 1
while (((9**5) * n_digits) >= 10**(n_digits-1)):
    n_digits += 1

# multiply 9^5 * n_digits-1 to get the max number to check
search_limit = (9**5) * (n_digits-1)
sum_fifth_power_digits = 0
num = 1

while (num < search_limit):
    sum_digits = 0
    for digit in str(num):
        sum_digits += int(digit)**5
    
    if sum_digits == num:
        sum_fifth_power_digits += num
    
    num += 1

print(f"Sum of all the numbers that can be written as the sum of the fifth power of its digits: {sum_fifth_power_digits}")