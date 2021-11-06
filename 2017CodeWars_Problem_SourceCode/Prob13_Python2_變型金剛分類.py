import math
import operator
import sys


def linearDistance(x,y):
    distance = 0;
    for i in range(0,2):
        distance += pow((x[i] - y[i]),2)
    return math.sqrt(distance)


def getTopKNeighbor(train,target,k):
    comlst = []
    for i in range(len(train)):
        dist = linearDistance(train[i],target)
        comlst.append((train[i],dist))

    sortedLST = sorted(comlst, key=lambda x:x[1])

    neighbor = []
    for item in range(k):
        neighbor.append(sortedLST[item][0][2])
    return neighbor


def most_common(lst):
    num = {}
    for item in lst:
        if item in num:
            num[item] += 1
        else:
            num[item] = 1

    freq = sorted(num, key=num.get, reverse=True)

    return freq[0]



if __name__ == "__main__":

    k = raw_input()
    data_set = raw_input()
    trainSet = list()
    testNum = list()

    for i in range(0,int(data_set)):
        (train_x,train_y,cate) = raw_input().split(' ')
        trainSet.append((int(train_x),int(train_y),cate))

    (tar_x, tar_y)=raw_input().split(' ')
    testNum.append(int(tar_x))
    testNum.append(int(tar_y))

    result = most_common(getTopKNeighbor(trainSet,testNum,int(k)))
    print result