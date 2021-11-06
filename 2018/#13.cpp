#include <stdio.h>
#include <limits.h>
  
// Define number of vertices in the graph
#define V 8
  
// Utility function to find the vertex with minimum distance value,
// from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// Utility function to print the constructed distance array
void printSolution(int dist[], int n) {
     for (int i = 1; i < (V-1); i++)
        printf("%d ", dist[i]);
     printf("%d", dist[V-1]);
}
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in the first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V);
}
  
int main() {

   int ab, ag, af, gc, bh, fc, ge, fe, bd, hc, hd, ed;

   //printf("Enter the values:\n");

   scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &ab, &ag, &af, &gc, &bh, &fc, &ge, &fe, &bd, &hc, &hd, &ed);

   int graph[V][V] = {{0, ab, 0, 0, 0, af, ag, 0},
                      {ab, 0, 0, bd, 0, 0, 0, bh},
                      {0, 0, 0, 0, 0, fc, gc, hc},
                      {0, bd, 0, 0, ed, 0, 0, hd},
                      {0, 0, 0, ed, 0, fe, ge, 0},
                      {af, 0, fc, 0, fe, 0, 0, 0},
                      {ag, 0, gc, 0, ge, 0, 0, 0},
                      {0, bh, hc, hd, 0, 0, 0, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
