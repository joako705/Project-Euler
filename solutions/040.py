# Problem URL: https://projecteuler.net/problem=40
# ----------------------------------------------------------
# An irrational decimal fraction is created by concatenating the positive integers.
# If d_n represents the nth digit of the fractional part, find the value of:
#    d_1 * d_10 * d_100 * d_1000 * d_10000 d_100000 * d_1000000

fractional_part = "".join(str(i) for i in range(1, (10**6 + 1)))

product = 1
for i in range(7):
    product *= int(fractional_part[10**i - 1])

print(f"Digit product: {product}")