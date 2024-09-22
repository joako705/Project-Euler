# Problem URL: https://projecteuler.net/problem=29
# ---------------------------------------------------------------------------------
# Find the number of distinct terms produced by a^b, where 2 <= a <= 100 and 2 <= b <= 100

distinct = set()

# brute force approach: check all combinations of a and b, add them to a set to automatically disallow duplicates
for a in range(2, 101):
    for b in range(2, 101):
        distinct.add(a**b)

print(f"Number of distinct terms found: {len(distinct)}")