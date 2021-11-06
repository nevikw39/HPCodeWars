import sys
from operator import itemgetter, attrgetter

sample = sys.argv[1]
target = list(sys.argv[2])
point_list = []
distance = []

#print sample + " " + str(target)

class point:
  def __init__(self,x,y,g):
    self.x = x
    self.y = y
    self.g = g
    
class disItem:
  def __init__(self, dis, g):
    self.dis = dis
    self.g = g


def parse(sample):
  flag = False
  for index in range(len(sample)):
    if sample[index] == '(':
      flag = True
      continue
    elif sample[index] == ')':
      flag = False
      continue
    else:
      if flag:
        x =  int(''.join(sample[index:index+2]))
        y =  int(''.join(sample[index+3:index+5]))
        g =  ''.join(sample[index+6])
        flag = False
        temp = point(x,y,g)
        point_list.append(temp)
        
def disCal(point, target):
  x = (point.x - target.x)
  y = (point.y - target.y)
  d_square = (x*x)+(y*y)
  return d_square
  
  
def countGroup(distance, k):
  a = 0
  b = 0
  for index in range(len(distance)):
    if index >= k:
      break
    else:
      if distance[index].g == 'a':
        a += 1
      elif distance[index].g == 'b':
        b += 1

  if a > b:
    return 'a'
  elif b > a:
    return 'b'
  else:
    return ''
      
      
parse(list(sample))
t_x = int(''.join(target[1:3]))
t_y = int(''.join(target[4:6]))
t_g = ''
target_point = point(t_x,t_y,t_g)


for item in point_list:
  dis = disCal(item, target_point)
  distance.append(disItem(dis, item.g))
  
distance.sort(key=attrgetter('dis'))
#for items in distance:
#  print 'dis: %d, g: %s' %(items.dis, items.g)
  
print countGroup(distance, 3) + countGroup(distance, 5)

