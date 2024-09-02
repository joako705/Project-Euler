# Problem URL: https://projecteuler.net/problem=42
# ----------------------------------------------------------------------------------------------------------
# Formula for nth triangle number: (n * (n+1)) / 2
# Word value: sum of the "value" of each letter (their position in the alphabet)
# ----------------------------------------------------------------------------------------------------------
# Find how many words in "42_words.txt" are "triangle" words (words whose value is a triangle number)

# can't use a simple relative path bc python.exe is 5543651342 miles away on my drive
file_path = "C:/Users/jpere/Documents/code/Project-Euler/extras/42_words.txt"

# read the file, split it at the commas, strip the double quotes around each word, and sort the list
with open(file_path) as file:
    long_ass_str = file.read()
    words = long_ass_str.split(',')

    for i in range(len(words)):
        words[i] = words[i].strip('""')
    
    words = sorted(words)

def get_alphabet_pos(letter):
    # this checks if the letter is "between" A and Z (using the the ASCII values)
    # then converts the letter to it's ASCII value with ord(), and then subtracts the ASCII value of 'A' (or 'a' if it's lowercase)
    if 'A' <= letter <= 'Z': return ((ord(letter) - ord('A')) + 1)
    elif 'a' <= letter <= 'z': return ((ord(letter) - ord('a')) + 1)

def count_words():
    triangle_nums = []
    triangle_words = []

    for n in range(1, 1001):
        triangle_nums.append(int((0.5*n)*(n+1)))

    for word in words:
        value = 0
        for letter in word:
            value += get_alphabet_pos(letter)
        
        for num in triangle_nums:
            if (value == num): triangle_words.append(word)
    
    return len(triangle_words)

print(f"There are {count_words()} triangle words in 42_words.txt")