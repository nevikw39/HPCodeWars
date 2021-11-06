from collections import deque

def dijkstra(reefs, routes):
    paths = {}
    visited = {0 : 0}
    destination = len(reefs)-1
    path = deque()

    while reefs:
        min_reef = None
        for reef in reefs:
            if reef in visited:
                if min_reef is None:
                    min_reef = reef
                elif visited[reef] < visited[min_reef]:
                    min_reef = reef
        if min_reef is None:
            break

        reefs.remove(min_reef)
        current_risk = visited[min_reef]

        for v in range(len(routes[min_reef])):
            try:
                risk = current_risk + routes[min_reef][v]
            except:
                continue
            if v not in visited or risk < visited[v]:
                visited[v] = risk
                paths[v] = min_reef


    prev = paths[destination]
    while prev != 0:
        path.appendleft(prev+1)
        prev = paths[prev]
    path.appendleft(1)
    path.append(destination+1)

    return path

def main():
    line = raw_input().split(' ')
    n = int(line[0])
    m = int(line[1])
    weight1 = int(line[2])
    weight2 = int(line[3])
    weight3 = int(line[4])

    reefs = set([i for i in range(n)])
    routes = [[None for i in range(n)] for j in range(n)]

    for i in range(m):
        line = raw_input().split(' ')
        risk_sum = int(line[2]) * weight1 + int(line[3]) * weight2 + int(line[4]) * weight3
        routes[int(line[0])-1][int(line[1])-1] = risk_sum
        routes[int(line[1])-1][int(line[0])-1] = risk_sum

    path = dijkstra(reefs, routes)
    print ' '.join(map(str, path))

if __name__ == '__main__':
    main()