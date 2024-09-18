# 
# ###############################################################################################################
# ## I use these functions in more than one problem, so I collected them into a separate file for importing :D ##
# ###############################################################################################################
# 

from os import path

# uses ord() to convert the letter to it's Unicode representation (ord('A') has to have +1 since Unicode is 0-indexed)
# it uses that corresponding number to perform arithmetic and return the letters position in the alphabet
def get_alphabet_pos(letter):
    # uppercase:
    if 'A' <= letter <= 'Z': return ord(letter) - ord('A') + 1
    # lowercase:
    elif 'a' <= letter <= 'z': return ord(letter) - ord('a') + 1

    return -1  # if it doesn't get a letter, return -1

def parse_file(file_name, split_char):
    script_dir = path.dirname(__file__) # get the directory of the current script
    file_path = path.join(script_dir, file_name) # construct a relative path to the file from the script directory

    with open(file_path) as file:
        text = file.read() # read the whole file into a string
        lines = text.split(split_char) # split the text of the file at the specified character     
        lines.sort() # sort the list
    
    return lines