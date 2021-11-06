import sys
import os

if __name__ == "__main__": 
	alphabet = list(raw_input())
	length = int(raw_input())
	for i in range(length):
		line = raw_input()
		for j in range(len(line)):
			if line[j]=='-':
				temp = alphabet[j]
				alphabet[j] = alphabet[j+1]
				alphabet[j+1] = temp
	print ("".join(alphabet))