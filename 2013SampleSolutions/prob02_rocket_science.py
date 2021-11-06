#!/usr/bin/env python
'''

CodeWars 2013
Rocket Science

'''
import sys

GRAM_PER_OZ = 28.3495231

for oz in sys.stdin:
    gram = float(oz) * GRAM_PER_OZ
    print ('%.4f' % gram)
