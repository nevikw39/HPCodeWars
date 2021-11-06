import sys, math
input = sys.stdin.readline()
parameter = input.split(",")
parameter[-1] = parameter[-1].replace("\n","")

if int(parameter[0]) >= int(parameter[1]):
  large = int(parameter[0])
  small = int(parameter[1])
else:
  large = int(parameter[1])
  small = int(parameter[0])

boarder_sqrt = math.pow(float(large), 2) - math.pow(float(small), 2)
boarder = int(math.sqrt(boarder_sqrt))

if boarder > small:
  print "(0,0),(0,%d),(%d,0)" %(boarder, small)
elif small > boarder: 
  print "(0,0),(0,%d),(%d,0)" %(int(small), boarder)
#else:
#  print "error"