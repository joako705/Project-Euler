# Problem URL: https://projecteuler.net/problem=22
# ---------------------------------------------------------------------------------
# Name score = sum of the position in the alphabet of each letter * the position of the name in the list
# ---------------------------------------------------------------------------------
# Find the sum of the scores of all the names listed in "022_names.txt"

from extras.euler_funcs import get_alphabet_pos, parse_file

# read the file and save each name in it into a list
names = parse_file("022_names.txt", ',')
sum_scores = 0

# go through all the names
for i in range(len(names)):
    temp_score = 0
    # go through each letter in the name (with the double quotes removed) and add up their position in the alphabet
    for letter in names[i].strip('"'):
        temp_score += get_alphabet_pos(letter)
    
    temp_score *= i+1 # multiply by the position in the list
    sum_scores += temp_score # add it to the total

print(f"Sum of all the names' scores: {sum_scores}")