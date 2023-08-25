#!/usr/bin/python3
def remove_char_at(s, n):
    if n < 0 or n >= len(s):
        return "Invalid index"

    new_str = []
    for i in range(len(s)):
        if i != n:
            new_str.append(s[i])
    return ''.join(new_str)