# python 3.3

import sys
import pdb

F=['G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G']
B=['B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B']
L=['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O']
R=['R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R']
U=['W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W']
D=['Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y']

def ReduceCommand (str):

  # no more i, 2, xyz, MES
  while str.find ('i') != -1:
    i = str.find ('i')
    str = str[:i] + str[i-1] + str[i-1] + str[i+1:]
    
  while str.find ('2') != -1:
    i = str.find ('2')
    str = str[:i] + str[i-1] + str[i+1:]
    
  str = str.replace('x', 'rLLL')
  str = str.replace('y', 'uDDD')
  str = str.replace('z', 'fBBB')
  #str = str.replace('x', 'Rlll')
#  str = str.replace('y', 'Uddd')
#  str = str.replace('z', 'Fbbb')
  
  str = str.replace('M', 'lLLL')
  str = str.replace('E', 'dDDD')
  str = str.replace('S', 'fFFF')
  
  return str
  
def Turn (s):
  global F, B, L, R, U, D
  
  if s == 'F':
    temp=F[0]
    F[0]=F[6]
    F[6]=F[8]
    F[8]=F[2]
    F[2]=temp
    
    temp=F[1]
    F[1]=F[3]
    F[3]=F[7]
    F[7]=F[5]
    F[5]=temp
    
    temp1=L[2] 
    temp2=L[5]
    temp3=L[8]
    
    L[2]=D[0]
    L[5]=D[1]
    L[8]=D[2]
    
    D[0]=R[6]
    D[1]=R[3]
    D[2]=R[0]
    
    R[6]=U[8]
    R[3]=U[7]
    R[0]=U[6]
    
    U[8]=temp1
    U[7]=temp2
    U[6]=temp3
    
  elif s == 'f':
    temp=F[0]
    F[0]=F[6]
    F[6]=F[8]
    F[8]=F[2]
    F[2]=temp
    
    temp=F[1]
    F[1]=F[3]
    F[3]=F[7]
    F[7]=F[5]
    F[5]=temp
    
    temp1=L[2] 
    temp2=L[5]
    temp3=L[8]
    
    L[2]=D[0]
    L[5]=D[1]
    L[8]=D[2]
    
    D[0]=R[6]
    D[1]=R[3]
    D[2]=R[0]
    
    R[6]=U[8]
    R[3]=U[7]
    R[0]=U[6]
    
    U[8]=temp1
    U[7]=temp2
    U[6]=temp3
    
    
    temp1=L[1]
    temp2=L[4]
    temp3=L[7]
    
    L[1]=D[3]
    L[4]=D[4]
    L[7]=D[5]
    
    D[3]=R[7]
    D[4]=R[4]
    D[5]=R[1]
    
    R[7]=U[5]
    R[4]=U[4]
    R[1]=U[3]
    
    U[5]=temp1
    U[4]=temp2
    U[3]=temp3
    
  elif s == 'B':
    temp=B[0]
    B[0]=B[6]
    B[6]=B[8]
    B[8]=B[2]
    B[2]=temp
    
    temp=B[1]
    B[1]=B[3]
    B[3]=B[7]
    B[7]=B[5]
    B[5]=temp
    
    temp1=R[2] 
    temp2=R[5]
    temp3=R[8]
    
    R[2]=D[8]
    R[5]=D[7]
    R[8]=D[6]
    
    D[8]=L[6]
    D[7]=L[3]
    D[6]=L[0]
    
    L[6]=U[0]
    L[3]=U[1]
    L[0]=U[2]
    
    U[0]=temp1
    U[1]=temp2
    U[2]=temp3
  elif s == 'b':
    temp=B[0]
    B[0]=B[6]
    B[6]=B[8]
    B[8]=B[2]
    B[2]=temp
    
    temp=B[1]
    B[1]=B[3]
    B[3]=B[7]
    B[7]=B[5]
    B[5]=temp
    
    temp1=R[2] 
    temp2=R[5]
    temp3=R[8]
    
    R[2]=D[8]
    R[5]=D[7]
    R[8]=D[6]
    
    D[8]=L[6]
    D[7]=L[3]
    D[6]=L[0]
    
    L[6]=U[0]
    L[3]=U[1]
    L[0]=U[2]
    
    U[0]=temp1
    U[1]=temp2
    U[2]=temp3
    
    
    temp1=R[1] 
    temp2=R[4]
    temp3=R[7]
    
    R[1]=D[5]
    R[4]=D[4]
    R[7]=D[3]
    
    D[5]=L[7]
    D[4]=L[4]
    D[3]=L[1]
    
    L[7]=U[3]
    L[4]=U[4]
    L[1]=U[5]
    
    U[3]=temp1
    U[4]=temp2
    U[5]=temp3
  elif s == 'L':
    temp=L[0]
    L[0]=L[6]
    L[6]=L[8]
    L[8]=L[2]
    L[2]=temp
    
    temp=L[1]
    L[1]=L[3]
    L[3]=L[7]
    L[7]=L[5]
    L[5]=temp
    
    temp1=B[2] 
    temp2=B[5]
    temp3=B[8]
    
    B[2]=D[6]
    B[5]=D[3]
    B[8]=D[0]
    
    D[6]=F[6]
    D[3]=F[3]
    D[0]=F[0]
    
    F[6]=U[6]
    F[3]=U[3]
    F[0]=U[0]
    
    U[6]=temp1
    U[3]=temp2
    U[0]=temp3
  
  elif s == 'l':
    temp=L[0]
    L[0]=L[6]
    L[6]=L[8]
    L[8]=L[2]
    L[2]=temp
    
    temp=L[1]
    L[1]=L[3]
    L[3]=L[7]
    L[7]=L[5]
    L[5]=temp
    
    temp1=B[2] 
    temp2=B[5]
    temp3=B[8]
    
    B[2]=D[6]
    B[5]=D[3]
    B[8]=D[0]
    
    D[6]=F[6]
    D[3]=F[3]
    D[0]=F[0]
    
    F[6]=U[6]
    F[3]=U[3]
    F[0]=U[0]
    
    U[6]=temp1
    U[3]=temp2
    U[0]=temp3
    
    
    temp1=B[1] 
    temp2=B[4]
    temp3=B[7]
    
    B[1]=D[7]
    B[4]=D[4]
    B[7]=D[1]
    
    D[7]=F[7]
    D[4]=F[4]
    D[1]=F[1]
    
    F[7]=U[7]
    F[4]=U[4]
    F[1]=U[1]
    
    U[7]=temp1
    U[4]=temp2
    U[1]=temp3
  elif s == 'R':
    temp=R[0]
    R[0]=R[6]
    R[6]=R[8]
    R[8]=R[2]
    R[2]=temp
    
    temp=R[1]
    R[1]=R[3]
    R[3]=R[7]
    R[7]=R[5]
    R[5]=temp
    
    temp1=U[2] 
    temp2=U[5]
    temp3=U[8]
    
    U[2]=F[2]
    U[5]=F[5]
    U[8]=F[8]
    
    F[2]=D[2]
    F[5]=D[5]
    F[8]=D[8]
    
    D[2]=B[6]
    D[5]=B[3]
    D[8]=B[0]
    
    B[6]=temp1
    B[3]=temp2
    B[0]=temp3
  elif s == 'r':
    temp=R[0]
    R[0]=R[6]
    R[6]=R[8]
    R[8]=R[2]
    R[2]=temp
    
    temp=R[1]
    R[1]=R[3]
    R[3]=R[7]
    R[7]=R[5]
    R[5]=temp
    
    temp1=U[2] 
    temp2=U[5]
    temp3=U[8]
    
    U[2]=F[2]
    U[5]=F[5]
    U[8]=F[8]
    
    F[2]=D[2]
    F[5]=D[5]
    F[8]=D[8]
    
    D[2]=B[6]
    D[5]=B[3]
    D[8]=B[0]
    
    B[6]=temp1
    B[3]=temp2
    B[0]=temp3

    
    temp1=U[1] 
    temp2=U[4]
    temp3=U[7]
    
    U[1]=F[1]
    U[4]=F[4]
    U[7]=F[7]
    
    F[1]=D[1]
    F[4]=D[4]
    F[7]=D[7]
    
    D[1]=B[7]
    D[4]=B[4]
    D[7]=B[1]
    
    B[7]=temp1
    B[4]=temp2
    B[1]=temp3
  elif s == 'U':
    temp=U[0]
    U[0]=U[6]
    U[6]=U[8]
    U[8]=U[2]
    U[2]=temp
    
    temp=U[1]
    U[1]=U[3]
    U[3]=U[7]
    U[7]=U[5]
    U[5]=temp
    
    temp1=F[0] 
    temp2=F[1]
    temp3=F[2]
    
    F[0]=R[0]
    F[1]=R[1]
    F[2]=R[2]
    
    R[0]=B[0]
    R[1]=B[1]
    R[2]=B[2]
    
    B[0]=L[0]
    B[1]=L[1]
    B[2]=L[2]
    
    L[0]=temp1
    L[1]=temp2
    L[2]=temp3
  elif s == 'u':
    temp=U[0]
    U[0]=U[6]
    U[6]=U[8]
    U[8]=U[2]
    U[2]=temp
    
    temp=U[1]
    U[1]=U[3]
    U[3]=U[7]
    U[7]=U[5]
    U[5]=temp
    
    temp1=F[0] 
    temp2=F[1]
    temp3=F[2]
    
    F[0]=R[0]
    F[1]=R[1]
    F[2]=R[2]
    
    R[0]=B[0]
    R[1]=B[1]
    R[2]=B[2]
    
    B[0]=L[0]
    B[1]=L[1]
    B[2]=L[2]
    
    L[0]=temp1
    L[1]=temp2
    L[2]=temp3
    
    
    temp1=F[3] 
    temp2=F[4]
    temp3=F[5]
    
    F[3]=R[3]
    F[4]=R[4]
    F[5]=R[5]
    
    R[3]=B[3]
    R[4]=B[4]
    R[5]=B[5]
    
    B[3]=L[3]
    B[4]=L[4]
    B[5]=L[5]
    
    L[3]=temp1
    L[4]=temp2
    L[5]=temp3
  elif s == 'D':
    temp=D[0]
    D[0]=D[6]
    D[6]=D[8]
    D[8]=D[2]
    D[2]=temp
        
    temp=D[1]
    D[1]=D[3]
    D[3]=D[7]
    D[7]=D[5]
    D[5]=temp
    
    temp1=F[8]
    temp2=F[7]
    temp3=F[6]
    
    F[8]=L[8]
    F[7]=L[7]
    F[6]=L[6]
    
    L[8]=B[8]
    L[7]=B[7]
    L[6]=B[6]
    
    B[8]=R[8]
    B[7]=R[7]
    B[6]=R[6]
    
    R[8]=temp1
    R[7]=temp2
    R[6]=temp3
  elif s == 'd':
    temp=D[0]
    D[0]=D[6]
    D[6]=D[8]
    D[8]=D[2]
    D[2]=temp
    
    temp=D[1]
    D[1]=D[3]
    D[3]=D[7]
    D[7]=D[5]
    D[5]=temp
    
    temp1=F[8]
    temp2=F[7]
    temp3=F[6]
    
    F[8]=L[8]
    F[7]=L[7]
    F[6]=L[6]
    
    L[8]=B[8]
    L[7]=B[7]
    L[6]=B[6]
    
    B[8]=R[8]
    B[7]=R[7]
    B[6]=R[6]
    
    R[8]=temp1
    R[7]=temp2
    R[6]=temp3
    
    
    temp1=F[5]
    temp2=F[4]
    temp3=F[3]
    
    F[5]=L[5]
    F[4]=L[4]
    F[3]=L[3]
    
    L[5]=B[5]
    L[4]=B[4]
    L[3]=B[3]
    
    B[5]=R[5]
    B[4]=R[4]
    B[3]=R[3]
    
    R[5]=temp1
    R[4]=temp2
    R[3]=temp3
  pass
def PrintRubik ():
  global F, B, L, R, U, D
  print (F[0]+F[1]+F[2], B[0]+B[1]+B[2], L[0]+L[1]+L[2], R[0]+R[1]+R[2],U[0]+U[1]+U[2], D[0]+D[1]+D[2])
  print (F[3]+F[4]+F[5], B[3]+B[4]+B[5], L[3]+L[4]+L[5], R[3]+R[4]+R[5],U[3]+U[4]+U[5], D[3]+D[4]+D[5])
  print (F[6]+F[7]+F[8], B[6]+B[7]+B[8], L[6]+L[7]+L[8], R[6]+R[7]+R[8],U[6]+U[7]+U[8], D[6]+D[7]+D[8])
  
  
# FLrU2xdiMluDzE
#BBR	WOG	RYR	YYG	WWO	OWB
#RYR	YWY	GBG	BGR	BOO	GRR
#YGO	GBB	WOG	YWY	WOB	OWR

#lrzSiE2FuDxbRM
#RYO	RBO	BYW	WBY	YWG	GGB
#RGY	GBG	ROW	RRW	GWY	WYB
#ROY	YRG	OOW	ROG	BOB	WBO

line = sys.stdin.readline()

#line = 'FLrU2xdiMluDzE'
#line='lrzSiE2FuDxbRM'
#line = 'F2'
#print (line)
line = ReduceCommand (line) # no more i, 2, xyz, MES
#print (line)

for s in line:
  Turn(s)

PrintRubik ()
  

  