#!/usr/bin/env python
'''
CodeWars 2013
Selling Shirts
'''
import sys

price_per_shirt = 8
fixed_cost = 95

for line in sys.stdin:
    sold = int(line)
    profit = (sold * price_per_shirt) - fixed_cost
    #print '%.2f' % profit
    print ('%d' % profit)
