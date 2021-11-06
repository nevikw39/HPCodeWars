import sys, io, re

(file, pattern) = sys.stdin.readline().strip().split(" ");
pattern = pattern.replace('"', '')

with open(file, "r") as fh:
    content = ''.join(fh.readlines())
    print content.count(pattern)
