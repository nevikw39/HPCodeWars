#!/usr/bin/env python
'''

CodeWars 2013

Distinct Letters
'''
import sys


def is_distinct(line):
    used_letters = []
    for c in line:
        if c in used_letters:
            return False
        else:
            used_letters.append(c)
    return True


def get_output(is_distinct):
    if is_distinct:
        return 'USES DISTINCT LETTERS'
    else:
        return 'DOES NOT USE DISTINCT LETTERS'

for linen in sys.stdin:
    line = linen.rstrip().upper()
    if line == '.':
        break
    print (line, get_output(is_distinct(line)))
