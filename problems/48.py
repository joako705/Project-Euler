#find the last 10 digits of the self powers series: 1^1 + 2^2 + 3^3 + ... + 1000^1000

series = 0

for i in range(1, 1001):
    series += i**i

print(f"The last 10 digits of the self powers series (from 1 to 1000) is: {str(series)[-10:]}")