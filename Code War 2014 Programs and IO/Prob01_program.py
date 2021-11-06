import os, re, sys
file = sys.stdin.readlines()
for line in file:
  temp = re.sub("[^a-zA-Z]"," ",line)
  words = temp.split()
  for word in words:
    print word