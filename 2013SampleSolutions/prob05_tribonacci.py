#!/usr/bin/env python
'''

CodeWars 2013
Tribonacci Numbers

'''
import sys

for line in sys.stdin:
    size = int(line)
    if size < 0:
        break

    trib = [0, 1, 1]
    while len(trib) < size + 1:
        num = sum(trib[-3:])
        trib.append(num)
    print (trib[size])
