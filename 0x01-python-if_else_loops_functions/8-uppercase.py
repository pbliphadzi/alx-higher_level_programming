#!/usr/bin/python3
def uppercase(s):
    result = ""
    for c in s:
        if 'a' <= c <= 'z':
            result += chr(ord(c) - (ord('a') - ord('A')))
        else:
            result += c
    print("{}".format(result))
