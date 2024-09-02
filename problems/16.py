# Problem URL: https://projecteuler.net/problem=16
# -----------------------------------------------------------
# Find the sum of the digits of 2^1000

sum = 0
big_ass_num = 2**1000
string = str(big_ass_num)

for digit in string:
    sum += int(digit)

print(f"Sum of the digits of 2^1000: {sum}")