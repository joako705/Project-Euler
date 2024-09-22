# Problem URL: https://projecteuler.net/problem=36
# ---------------------------------------------------------------------------------
# Find the sum of all numbers, under 1 million, which are palindromic in base 10 and base 2

sum_pals = 0

for i in range(10**6):
    str_num = str(i) # convert the num to a string in order to reverse it
    # if the number is palindromic, check if it's also palindromic in binary
    if (str_num == "".join(reversed(str_num))):
        # bin() returns the binary representation of a number as a string, with the "0b" prefix, which i remove using string slicing
        bin_num = bin(i)[2:]
        if (bin_num == "".join(reversed(bin_num))):
            sum_pals += i # if the number is *also* palindromic in binary, add it to the rolling sum

print(f"Sum of all double palindromes (base 10 & base 2) under 1 million is: {sum_pals}")