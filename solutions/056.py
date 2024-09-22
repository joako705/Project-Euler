# Problem URL: https://projecteuler.net/problem=56
# ---------------------------------------------------------------------------------
# For natural numbers a, b < 100, what is the maximum digital sum of a^b?

max_digital_sum = 0

# check all combinations of a and b
for a in range(1, 100):
    for b in range(1, 100):
        digit_sum = 0
        num = str(a**b) # calculate a^b and convert it to a string

        # add up all the digits in num
        for digit in num:
            digit_sum += int(digit)
        
        # check if num's digit sum is greater than the current max
        if max_digital_sum < digit_sum: max_digital_sum = digit_sum
    
print(f"Maxmimum digital sum of a^b (for a, b < 100): {max_digital_sum}")