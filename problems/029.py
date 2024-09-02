# Problem URL: https://projecteuler.net/problem=29
# -----------------------------------------------------------------------------------------------------------------
# For a^b, where a and b are integers between 2 and 100, find the number of distinct terms produced by a^b

distinct = set()

for a in range(2, 101):
    for b in range(2, 101):
        distinct.add(a**b)

print(f"Number of distinct terms: {len(distinct)}")