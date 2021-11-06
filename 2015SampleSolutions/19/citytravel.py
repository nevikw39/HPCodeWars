import sys 
def shortestpath(graph,start,end,visited=[],distances={},predecessors={}): 
   
    if start==end: 
        path=[] 
        while end != None: 
            path.append(end) 
            end=predecessors.get(end,None) 
        return distances[start], path[::-1] 
    
    if not visited:
        distances[start]=0 
    
    for neighbor in graph[start]: 
        if neighbor not in visited: 
            neighbordist = distances.get(neighbor,sys.maxint) 
            tentativedist = distances[start] + graph[start][neighbor] 
            if tentativedist < neighbordist: 
                distances[neighbor] = tentativedist 
                predecessors[neighbor]=start 
    
    visited.append(start) 
    
    unvisiteds = dict((k, distances.get(k,sys.maxint)) for k in graph if k not in visited) 
    closestnode = min(unvisiteds, key=unvisiteds.get) 
    
    return shortestpath(graph,closestnode,end,visited,distances,predecessors) 
 
if __name__ == "__main__": 
    graph = {}
    length = int(raw_input())
    for i in range(length):
        line = raw_input().split(' ')
        if line[0] not in graph:
            graph[line[0]] = {}
        graph[line[0]][line[1]] = int(line[2])
        if line[1] not in graph:
            graph[line[1]] = {}
        graph[line[1]][line[0]] = int(line[2])

    inoutcity = raw_input().split(' ')
    price, cities = shortestpath(graph,inoutcity[0],inoutcity[1])
    print str(price)+' '+" ".join(cities)