def Round (pay):
    if (pay%1*10) > 4 :
        pay = pay+1
    return int(pay)

dist=float(input())
if dist<20:
    print '0\n'
elif dist <200:
    print '%d\n' %(Round((dist-20) * 1.2))
else:
    print '%d\n' %(Round(((dist-200) * 0.9) +(200-20)*1.2))
