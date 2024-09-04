# Problem URL: https://projecteuler.net/problem=24
# -------------------------------------------------------
# Find the millionth lexicographic permutation of the digits 0-9.
# Lexicographic means they're ordered numerically or alphabetically

from itertools import permutations

def find_permutations(iterable):
    return list(permutations(iterable))

nums = '0123456789'
perms = sorted(find_permutations(nums))

print(f"Millionth lexicographic permutations of the digits 0-9: {''.join(perms[10**6 - 1])}")