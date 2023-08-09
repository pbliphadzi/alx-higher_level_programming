from itertools import combinations

for digit1, digit2 in combinations(range(10), 2):
    print(f"{digit1}{digit2}", end=", ")

print("89")