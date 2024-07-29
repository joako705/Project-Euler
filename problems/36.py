#find the sum of all numbers, less than 1 million, which are palindromic in base 10 and base 2

double_pals = []
sum_pals = 0

for num in range(1000000):
    if (str(num) == "".join(reversed(str(num)))):
        bin_num = bin(num)[2:]
        if (bin_num == "".join(reversed(bin_num))):
            double_pals.append(num)


for pal in double_pals:
    sum_pals += pal

print(double_pals)
print(f"The sum of all double palindromes (base 10 and base 2) under 1 million is: {sum_pals}")