# Problem URL: https://projecteuler.net/problem=42
# ---------------------------------------------------------------------------------
# Formula for nth triangle number: (n * (n+1)) / 2
# Word value = sum of the "value" of each letter (their position in the alphabet)
# ---------------------------------------------------------------------------------
# Find how many words in "042_words.txt" are "triangle" words (words whose value is a triangle number)

from extras.euler_funcs import get_alphabet_pos, parse_file

# read the file and save each word in it into a list
words = parse_file("042_words.txt", ',')
triangle_nums = []
triangle_words = []

# precompute the first 1000 triangle numbers
for n in range(1, 1001):
    triangle_nums.append(int((0.5*n)*(n+1)))

for word in words:
    value = 0
    # calculate the current word's value
    for letter in word.strip('""'): # strip leading and trailing double quotes
        value += get_alphabet_pos(letter)
    
    # check if the word value is a triangle number
    if value in triangle_nums: triangle_words.append(word)

print(f"There are {len(triangle_words)} triangle words in 042_words.txt")