# Problem URL: https://projecteuler.net/problem=24
# ---------------------------------------------------------------------------------
# Find the millionth lexicographic permutation of the digits 0-9

from itertools import permutations

# returns a list of tuples that represent each permutation of the provided string
# however, the tuples save each character in the string as an individual element
def find_permutations(string):
    return list(permutations(string))

digits = '0123456789'

# this list comprehension converts each tuple in the list returned by find_permutations() into a string
# sorted() is used beforehand so the list is in lexicographic order
# .join() appends the iterators of the tuple 'x' to an empty string, and that string gets added to the 'perms' list
perms = [''.join(x) for x in sorted(find_permutations(digits))]

# now, the millionth index in 'perms' is the millionth lexicographic permutation, and it can just be printed by accessing that index
print(f"Millionth lexicographic permutations of the digits 0-9: {perms[10**6 - 1]}")