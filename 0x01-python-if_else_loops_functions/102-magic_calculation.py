#!/usr/bin/python3
def magic_calculation(a, b, c):
    if a < b and c > b:
        return c
    elif c > b:
        return a + b
    else:
        return a * b - c