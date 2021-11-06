def BatCallenge(line):
    result = 0
    number=list(line.split(" "))
    length = int(number[0])
    distance = int(number[1])
    existingBats=int(number[2])
    if existingBats==0:
        result=int((length - 12)/distance) + 1
    else:
        batsPos=list(number[3:])
        result=0
        initPos=6
        for i in range(0, existingBats):
            if i!=0:
                result+=int((int(batsPos[i]) - initPos)/distance) - 1
            else:
                result+=int((int(batsPos[i]) - initPos)/distance)
            initPos=int(batsPos[i])
        finalPos=length - 6
        result+= int((finalPos - initPos)/distance) 
    
    print(result)

if __name__ == '__main__':
    line = input()
    if line is not None:
        BatCallenge(line)