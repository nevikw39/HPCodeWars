#!/bin/python

def CodeWar2018_Salted_Egg(q):
    n = len(q)
    total_swaps = 0
    for i in xrange(n):
        swaps = 0
        while q[i]-1 != i:
            t = q[i]
            if t > n:
                q[i] = q[n-1]
                q[n-1] = t
                break
            else:
                q[i] = q[t-1]
                q[t-1] = t
            swaps += 1
        total_swaps += swaps
    return total_swaps

                    
if __name__ == '__main__':
    n = int(raw_input())
    q = map(int, raw_input().rstrip().split())
    print CodeWar2018_Salted_Egg(q)
