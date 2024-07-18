#for a^b, where a and b are integers between 2 and 100, find the number of distinct terms produced by a^b

distinct = set()

for a in range(2, 101):
    for b in range(2, 101):
        distinct.add(a**b)

print(f"The number of distinct terms is: {len(distinct)}")