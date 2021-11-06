#!/usr/bin/python

import sys

p = 0
g = 0
y = 0
C = 0
r = 0
R = 0

v = True

for line in sys.stdin:
    tokens = line.split("=")
    if tokens[0] == "p":
        if p != 0:
            # print earlier result
            if v:
                print 1
            else:
                print 0
        p = int(tokens[1])
	# print "p="+str(p)
        v = True
    if tokens[0] == "g":
        g = int(tokens[1])
	# print "g="+str(g)
    if tokens[0] == "y":
        y = int(tokens[1])
	# print "y="+str(y)
    if tokens[0] == "C":
        C = int(tokens[1])
    if tokens[0] == "r":
        r = int(tokens[1])
        if ((g ** r) % p) != C:
            v = False
    if tokens[0] == "R":
        R = int(tokens[1])
        v1 = (C*y) % p
        v2 = (g ** R) % p
        if v1 != v2:
            v = False

# print last result 
if v:
    print 1
else:
    print 0