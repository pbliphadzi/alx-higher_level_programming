#!/usr/bin/python3

for char_number in range(122, 96, -1):
    print("{lowercase}{uppercase}".format(lowercase=chr(char_number), uppercase=chr(char_number - (ord('a') - ord('A')))), end="")

