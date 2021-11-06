#!/usr/bin/env python
'''

CodeWars 2013

Counting Ones
'''
import sys


def count_ones(n):
    count = 0
    for v in range(n + 1):
        for c in str(v):
            if c == '1':
                count += 1
    return count

for line in sys.stdin:
    n = int(line)
    if n < 0:
        break
    print ('%d' % count_ones(n))
