import re

s = raw_input()
#print(s)

m = re.findall('\(([0-9]*),([0-9]*)\)', s)

#for (a,b) in m:
#	print ("x="+a+" y="+b)

def cal(coords, prex, prey):
	if len(coords) == 0:
		return abs(prex-0) + abs(prey-0)
	ret = 2147483647
	for i in range(0, len(coords)):
		(curx,cury) = coords[i]
		ret = min(ret, cal(coords[0:i]+coords[i+1:], curx, cury) + abs(curx-prex) + abs(cury-prey))
	return ret

#	print ("x="+a+" y="+b)
#	cal(coords[1:])

m = [(int(a), int(b)) for (a,b) in m]

print cal(m, 0, 0)
