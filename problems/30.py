#find the sum of all the numbers that can be written as the sum of the fifth power of their digits

#first you gotta figure out when to stop checking numbers and their digits:
#for digits 1-9, the max any digit raised to the fifth can equal is 9^5
#therefore, for a number with n-digits, the absolute maximum the sum of its digits' fifth powers can be is (9^5)*n
n_digits = 1

#however, the value of an n-digit number increases exponentionally as n increases (10^n)
#this means that eventually, there'll be an n-digit number that CAN'T be written as the sum of the fifths of its digits,
#because that sum will be smaller than the number itself. enter this while loop:
while (((9**5) * n_digits) >= 10**(n_digits-1)):
    n_digits += 1

search_limit = (9**5) * (n_digits-1) #n-1 bc when the while loop breaks, the last iteration will have increase n past the limit

sum_fifth_power_digits = 0
num = 2

while (num < search_limit):
    sum_digits = 0
    for digit in str(num):
        sum_digits += int(digit)**5
    
    if sum_digits == num:
        sum_fifth_power_digits += num
    
    num += 1

print(f"The sum of all the numbers that can be written as the sum of the fifth power of its digits: {sum_fifth_power_digits}")