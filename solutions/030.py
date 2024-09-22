# Problem URL: https://projecteuler.net/problem=30
# ---------------------------------------------------------------------------------
# Find the sum of all the numbers that can be written as the sum of the fifth power of their digits

# ---------------------------------------------------------------------------------
# in order to not check numbers infinitely, a search limit needs to be calculated:
# for all digits 0-9, the max that any of them raised to the fifth can equal is 9^5.
# therefore, for a number with n-digits, the absolute maximum the sum of its fifths can be is (9^5)*n.
# however, the maximum value of an n-digit number increases exponentionally as n increases (10^n).
# this means that eventually, there'll be an n-digit number that *can't* be written as the sum of its fifths, since that sum would be smaller than the number itself
# ---------------------------------------------------------------------------------

# to find this limit, n_digits needs to be incremented until the maximum value of an n-digit number is larger than the maximum possible sum of its fifths
n_digits = 1
while ((9**5) * n_digits >= 10**(n_digits)):
    n_digits += 1

# calculate the maximum possible number that could be written as the sum of its fifths
search_limit = (9**5) * (n_digits-1) # -1 since when the while loop ends, n_digits will have been incremented one too many times
answer = 0

for num in range(1, search_limit):
    sum_digits = 0
    
    # calculate num's sum of fifths
    for digit in str(num):
        sum_digits += int(digit)**5
    
    # check if that sum is equal to the number itself
    if sum_digits == num: answer += num

print(f"Sum of all the numbers that can be written as the sum of the fifth power of its digits: {answer}")