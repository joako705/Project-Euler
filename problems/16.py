#find the sum of the digits of 2^1000
#once again in python bc of the size of the number

sum = 0
big_ass_num = 2**1000
string = str(big_ass_num)

for char in string:
    sum += int(char)

print(f"The sum of the digits of 2^1000 is: {sum}")