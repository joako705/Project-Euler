#nth triangle number: sum of natural numbers up to n
#word value: sum of the "value" of each letter (their position in the alphabet)
#find how many words in 42_words.txt are "triangle" words (that their word value is a triangle number)

#i wanted put this function in a separate module in the helpers folder but idk how to do that in python yet,
#so i just copied it and the file parsing code from problem 22
def get_alphabet_pos(letter):
    #this converts the letter to it's ascii value with ord() and then subtracts the ascii value of 'A' (or 'a' if it's lowercase)
    #checks if the letter is "between" A and Z (god bless python's weird ass string arithmetic)
    if 'A' <= letter <= 'Z': return ((ord(letter) - ord('A')) + 1)
    elif 'a' <= letter <= 'z': return ((ord(letter) - ord('a')) + 1)
    else: return None #in case it doesn't get a letter as input

with open("C:/Users/jpere/Documents/code/Project-Euler/helpers/42_words.txt") as file:
    long_ass_str = file.read()
    words = long_ass_str.split(',') #make a list of all the words by splitting the long ass string at the commas

#get rid of the double quotes surrounding each word
for i in range(len(words)):
    words[i] = words[i].replace('"', '')

triangle_nums = []
triangle_words = []

#find triangle numbers up to 1000 using the formula
for n in range(1, 1001):
    triangle_nums.append(int((0.5*n)*(n+1)))

for word in words:
    value = 0
    for letter in word:
        value += get_alphabet_pos(letter)
    
    for num in triangle_nums:
        if (value == num): triangle_words.append(word)

print(f"There are {len(triangle_words)} triangle words in 42_words.txt")
