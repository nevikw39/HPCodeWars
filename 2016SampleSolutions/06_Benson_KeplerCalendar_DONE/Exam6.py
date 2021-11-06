import sys

def weekofday(y,m,d):
    return (385 * (y - 1) + 
           int((y-1)/5) - int((y-1)/100) + int((y-1)/500) + 
           32 * (m-1) + 
           d + 
           (1 if m>3 else 0) + 
           (1 if m> 9 and (y%500==0 or (y%100!=0 and y%5==0)) else 0)) % 7
           
d = [int(i) for i in sys.stdin.readline().strip().split(' ')]
print "7123456"[weekofday(d[0], d[1], d[2])]
