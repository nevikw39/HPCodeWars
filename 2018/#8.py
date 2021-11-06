#!/bin/python

def CodeWar2018_Dorayaki(n, queries):
    result = [ 0 for _ in range(n+1) ]
    for action in queries:
        start = action[0]
        stop = action[1]
        delta = action[2]

        result[start] += delta
        if stop+1 <= n:
            result[stop+1] -= delta

    max_item = 0
    temp = 0
    for item in result:
        temp += item
        if temp > max_item:
            max_item = temp        
    return max_item

if __name__ == '__main__':
    nm = raw_input().split()
    n = int(nm[0])
    m = int(nm[1])
    queries = []
    for _ in xrange(m):
        queries.append(map(int, raw_input().rstrip().split()))
    result = CodeWar2018_Dorayaki(n, queries)
    print result
