#!/usr/bin/python3
for alpha_qe in range(97, 123):
    if alpha_qe != 101 and alpha_qe != 113:
        print("{character}".format(character=chr(alpha_qe)), end="")