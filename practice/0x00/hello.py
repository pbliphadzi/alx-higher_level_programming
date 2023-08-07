#!/usr/bin/env python3

a,b = 0, 1

while a < 100000:
    print(a);
    a,b = b, a+b
