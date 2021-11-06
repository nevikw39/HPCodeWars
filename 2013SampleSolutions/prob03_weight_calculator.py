#!/usr/bin/env python
'''

CodeWars 2013

Weight Calculator
'''
import sys

for linen in sys.stdin:
    line = linen.rstrip()
    name, earth_weight, planet, conversion = line.split()
    if name == 'END':
        break
    weight = float(earth_weight) * float(conversion)
    print ('On %s, %s would weigh %g pounds.' % (planet, name, weight))
