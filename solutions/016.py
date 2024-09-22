# Problem URL: https://projecteuler.net/problem=16
# ---------------------------------------------------------------------------------
# Find the sum of the digits of 2^1000

digit_sum = 0
BigNum = 2**1000

# convert the number to a string, iterate through every digit, and add them all up
num_string = str(BigNum)
for digit in num_string:
    digit_sum += int(digit)

print(f"Sum of the digits of 2^1000: {digit_sum}")