#find the sum of the scores of the names in the file
#name score = sum of the position in the alphabet of each letter in the name * the position of the name in the list

def get_alphabet_pos(letter):
    #this converts the letter to it's ascii value with ord() and then subtracts the ascii value of 'A' (or 'a' if it's lowercase)
    #checks if the letter is "between" A and Z (god bless python's weird ass string arithmetic)
    if 'A' <= letter <= 'Z': return ((ord(letter) - ord('A')) + 1)
    elif 'a' <= letter <= 'z': return ((ord(letter) - ord('a')) + 1)
    else: return None #in case it doesn't get a letter as input

with open("C:/Users/jpere/Documents/code/Project-Euler/helpers/22_names.txt") as file:
    long_ass_str = file.read()
    names = long_ass_str.split(',') #make a list of all the names by splitting the long ass string at the commas

#get rid of the double quotes surrounding each name
for i in range(len(names)):
    names[i] = names[i].replace('"', '')

names = sorted(names)

scores = []
sum_scores = 0

for i in range(len(names)):
    temp_score = 0
    for char in names[i]:
        temp_score += get_alphabet_pos(char)
    
    temp_score *= i+1
    scores.append(temp_score)

for score in scores:
    sum_scores += score

print(f"The sum of all the name scores is: {sum_scores}")