#!/usr/bin/python3
from itertools import combinations

for digit1, digit2 in combinations(range(10), 2):
    print("{}{}".format(digit1, digit2), end=", ")

print("89")