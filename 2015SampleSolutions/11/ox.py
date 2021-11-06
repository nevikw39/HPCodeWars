import sys

#012
#345
#678

input = sys.argv[1]

def printMatrix (str):
  print ("%s%s%s" %(str[0], str[1], str[2]))
  print ("%s%s%s" %(str[3], str[4], str[5]))
  print ("%s%s%s" %(str[6], str[7], str[8]))
  print ("")
  
def checkWin (str):
  
  win = False
  winner = "A"
  
  #Horizontal checking
  if (str[0] == str[1]) and (str[0] == str[2]):
    #print "%s Win!" %(str[0])
    win = True
    winner = str[0]
  elif (str[3] == str[4]) and (str[3] == str[5]):
    #print "%s Win!" %(str[3])
    win = True
    winner = str[3]
  elif (str[6] == str[7]) and (str[6] == str[8]):
    #print "%s Win!" %(str[7])
    win = True
    winner = str[7]
  #Vertical checking
  elif (str[0] == str[3]) and (str[0] == str[6]):
    #print "%s Win!" %(str[0])
    win = True
    winner = str[0]
  elif (str[1] == str[4]) and (str[1] == str[7]):
    #print "%s Win!" %(str[1])
    win = True
    winner = str[1]
  elif (str[2] == str[5]) and (str[2] == str[8]):
    #print "%s Win!" %(str[2])
    win = True
    winner = str[2]
  #Slash checking
  elif (str[0] == str[4]) and (str[0] == str[8]):
    #print "%s Win!" %(str[0])
    win = True
    winner = str[0]
  elif (str[2] == str[4]) and (str[2] == str[6]):
    #print "%s Win!" %(str[2])
    win = True
    winner = str[2]

    
  return win, winner

if len(input) != 9:
  print ("ERROR: string length must be 9 (current length: %d)" %(len(input)))
  sys.exit(0)

#validate the input and decide who's turn it is
O_count = 0
X_count = 0
A_count = 0

for char in input:
  if char == "O":
    O_count += 1
  elif char == "X":
    X_count += 1
  elif char == "A":
    A_count += 1;
  else:
    print ("ERROR: input contains invalid character: %s" %(char))
    sys.exit(0)
    
#print "O: %d, X: %d, A: %d" %(O_count, X_count, A_count)
#printMatrix(input)

if X_count > O_count:
  print ("invalid input. X can't be more than O because O goes first (O: %d, X: %d)" %(O_count, X_count))
  sys.exit(0)
if (O_count - 1) > X_count:
  print ("invalid input. O can't be more than X by 2 or more (O: %d, X: %d)" %(O_count, X_count))
  sys.exit(0)
  
if O_count == X_count:
  #print "next turn is O"
  next = "O"
elif O_count > X_count:
  #print "next turn is X"
  next = "X"
else:
  print ("ERROR: makes no sense")
  sys.exit(0)

def recursive(this, tempstr, max_level, level):
  if level > max_level:
    #print "exceed max %d" %(max_level)
    return
    
  if this == "O":
    next = "X"
  elif this == "X":
    next = "O"
  else:
    print ("ERROR: unidentified char: %s" %(this))
    sys.exit(0)
    
  for index in range(len(tempstr)):
    if tempstr[index] == "A":
      tempstr[index] = this;
      won, whowon = checkWin(tempstr)
      #printMatrix(tempstr);
      if won and whowon == "O":
        print ("yes")
        sys.exit(0)
      elif won and whowon == "X":
        return
      recursive(next, tempstr, max_level, level+1)
      tempstr[index] = "A";
      
#recursive(next, list(input), 3, 1)
if next == "X":
  recursive(next, list(input), 4, 1)
elif next == "O":
  recursive(next, list(input), 3, 1)
else:
  print ("ERROR: wrong next step: %s" %(next))

print ("no")











