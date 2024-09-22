# Problem URL: https://projecteuler.net/problem=40
# ---------------------------------------------------------------------------------
# An irrational decimal fraction is created by concatenating the positive integers:
# 0.123456789101112131415161718192021...
# ---------------------------------------------------------------------------------
# If d-n represents the nth digit of the fractional part, find the value of the following product:
# d-1 * d-10 * d-100 * d-1,000 * d-10,000 d-100,000 * d-1,000,000

# concatenate the first million positive integers into a string
fractional_part = ''.join(str(i) for i in range(1, (10**6 + 1)))

product = 1
for i in range(7): # use powers of 10 to access the desired digits
    product *= int(fractional_part[10**i - 1])

print(f"Digit product: {product}")