#for a, b < 100, what is the maximum digital sum of a^b?

max_sum = 0

for a in range(1, 100):
    for b in range(1, 100):
        sum = 0
        num = str(a**b)
        for digit in num:
            sum += int(digit)
        
        if max_sum < sum: max_sum = sum
    
print(max_sum)