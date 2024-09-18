# Problem URL: https://projecteuler.net/problem=22
# ---------------------------------------------------------------------------------------------------------------------
# Find the sum of the scores of all the names in "22_names.txt"
# "score" = sum of the position in the alphabet of each letter in the name * the position of the name in the list

# can't use a simple relative path bc python.exe is 5543651342 miles away on my drive
file_path = "C:/Users/jpere/Documents/code/Project-Euler/extras/22_names.txt"

# read the file, split it at the commas, strip the double quotes around each name, and sort the list
with open(file_path) as file:
    long_ass_str = file.read()
    names = long_ass_str.split(',')

    for i in range(len(names)):
        names[i] = names[i].strip('""')
    
    names = sorted(names)

def get_alphabet_pos(letter):
    # this checks if the letter is "between" A and Z (using the the ASCII values)
    # then converts the letter to it's ASCII value with ord(), and then subtracts the ASCII value of 'A' (or 'a' if it's lowercase)
    if 'A' <= letter <= 'Z': return ((ord(letter) - ord('A')) + 1)
    elif 'a' <= letter <= 'z': return ((ord(letter) - ord('a')) + 1)

def find_sum():
    scores = []
    sum_scores = 0

    for i in range(len(names)):
        temp_score = 0
        for letter in names[i]:
            temp_score += get_alphabet_pos(letter)
        
        temp_score *= i + 1
        scores.append(temp_score)

    for score in scores:
        sum_scores += score
    
    return sum_scores

print(f"Sum of all the name scores: {find_sum()}")