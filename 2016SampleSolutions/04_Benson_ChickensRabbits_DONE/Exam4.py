import sys

inputs=sys.stdin.readline().strip()

(count,feet)=[int(i) for i in inputs.split(' ')]

rabbit = (feet - count * 2) / 2
chicken = count - rabbit

if rabbit < 0 or chicken < 0 or int(rabbit)!=rabbit or int(chicken)!=chicken: # or chicken*2+rabbit*4!=feet:
   print("None")
else:
   print(str(int(rabbit)) + " " + str(int(chicken)))
