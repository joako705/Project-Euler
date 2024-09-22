# Problem URL: https://projecteuler.net/problem=48
# ---------------------------------------------------------------------------------
# Find the last 10 digits of the self powers series: 1^1 + 2^2 + 3^3 + ... + 1000^1000

# first calculate the series
series = 0
for i in range(1, 1001):
    series += i**i

# then convert the result to a string, and use string slicing to only print the last 10 digits
print(f"Last 10 digits of the self powers series: {str(series)[-10:]}")