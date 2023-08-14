#!/usr/bin/python3

def multiple_returns(sen):
    if sen != '':
        char = sen[0]
    else:
        char = None
    return (len(sen), char)