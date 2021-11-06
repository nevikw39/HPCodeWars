# python 3

import sys
import pdb



def PrintMap (w, h, m):
  for j in range(0, h):
    for i in range(0, w):
      print (m[j * w + i],)
    print ('')

def ShrinkOneEdge (w, h, m):
  if w == 0 or h == 0:
    return 0, 0, []
  
  # top
  for i in range(0,w):
    if m[0*w+i]==1:
      break
    if i == w-1:
      m = m[w:w*h]
      h=h-1
      
  # bottom
  for i in range(0,w):
    if m[(h-1)*w+i]==1:
      break
    if i == w-1:
      m = m[0:w*h-w]
      h=h-1
  # left
  for j in range(0,h):
    if m[j*w+0]==1:
      break
    if j == h-1:
      m2=[]
      for j in range(0,h):
        for i in range(1,w):
          m2.append(m[j*w+i])
      m=m2
      w=w-1
      break
      
  # right
  for j in range(0,h):
    if m[j*w+w-1]==1:
      break
    if j == h-1:
      m2=[]
      for j in range(0,h):
        for i in range(0,w-1):
          m2.append(m[j*w+i])
      m=m2
      w=w-1
      break
  return w, h, m
    
def Shrink (w, h, m):
  if w == 0 or h == 0:
    return 0, 0, []

  while True:
    w0=w
    h0=h
    w,h,m=ShrinkOneEdge(w,h,m)
    if w == w0 and h == h0:
      break
  return w,h,m

def Next (w, h, m):
  
  if w == 0 or h == 0:
    return 0, 0, []

  
  w2=w+2
  h2=h+2
  
  map2 = []
  
  for j in range(0, h2):
    for i in range(0, w2):
      count = 0
      #print i, j
      
      # top-left
      if i==0 or i ==1 or j == 0 or j == 1:
        pass
      else:
        if map[(j - 1 - 1) * w + (i - 1 - 1)] == 1:
          count=count+1
      # top
      if j==0 or j ==1 or i == 0 or i == (w+1):
        pass
      else:
        if map[(j - 1 - 1) * w + (i - 1)] == 1:
          count=count+1
      # top-right
      if i==w or i==(w+1) or j==0 or j==1:
        pass
      else:
        if map[(j - 1 - 1) * w + (i - 1 + 1)] == 1:
          count=count+1
      # left
      if i==0 or i ==1 or j ==0 or j == (h + 1):
        pass
      else:
        if map[(j - 1) * w + (i - 1 - 1)] == 1:
          count=count+1
      # right
      if i==w or i ==(w+1) or j == 0 or j == (h + 1):
        pass
      else:
        if map[(j - 1) * w + (i - 1 + 1)] == 1:
          count=count+1
      # bottom-left
      if j==h or j ==(h+1) or i ==0 or i == 1:
        pass
      else:
        if map[(j - 1 + 1) * w + (i - 1 - 1)] == 1:
          count=count+1
      # bottom
      if j==h or j ==(h+1) or i == 0 or i == (w + 1):
        pass
      else:
        if map[(j - 1 + 1) * w + (i - 1)] == 1:
          count=count+1
      # bottom-right
      if j==h or j ==(h+1) or i==w or i ==(w+1):
        pass
      else:
        if map[(j - 1 + 1) * w + (i - 1 + 1)] == 1:
          count=count+1
          
      #print j, i, count
      #pdb.set_trace()
      
      if count == 2:
        if i==0 or i == (w+1) or j==0 or j==(h+1):
          map2.append(0)
        elif map[(j - 1) * w + (i - 1)] == 1:
          map2.append(1)
        else:
          map2.append(0)
      elif count == 3:
        map2.append(1)
      else:
        map2.append(0)
      
      
  #print map2

  
  return w2, h2, map2

  
# 4 2 01111110 1
# 4 4 1100100000010011 1

line = sys.stdin.readline()

#print line

#width = 4
#height = 2
#mapStr = '01111110'
#period = 2
#map = [0, 1, 1, 1, 1, 1, 1, 0]


a = line.split(' ') 
if len(a) != 4:
  exit()
  print ('error input')
  
width = int(a[0])
height = int(a[1])
mapStr = a[2]
period = int(a[3])

map =[]
for s in mapStr:
  map.append(int(s))


  
#PrintMap (width, height, map)

for i in range(0, period):
  width, height, map = Next (width, height, map)
  #PrintMap (width, height, map)
  width, height, map = Shrink (width, height, map)
  #print '----------'
  #PrintMap (width, height, map)

mapStr=''
for j in range(0, height):
  for i in range(0, width):
    #pdb.set_trace()
    mapStr = mapStr + str(map[j*width+i])
print (width, height, mapStr)

  
#pdb.set_trace()


pass


  