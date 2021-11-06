#include <iostream>
#include <queue>

using namespace std;
const int N = 10; // row & column
const int Initial = 65536;
const int Repeat = 10; // Max visit times
const int NA = -1;
typedef pair<int, int> BoxPair;
typedef pair<int, int> IronManPair;
typedef pair<BoxPair, IronManPair> myPair;

int map[N][N] = {
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 0, 2, 0, 0, 1, 1 },
{ 1, 1, 4, 0, 3, 0, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } }; // hard code map (Example 1), Answer = 2

int dist[N][N];
int dist_Repeat[N][N]; // visit time
int ironMandist[N][N];
int Sx, Sy; // Start coordinate
int Tx, Ty; // Target coordinate
int Ix, Iy; // IronMan coordinate
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };  // next move
int rx[4] = { -1, 0, 1, 0 }, ry[4] = { 0, -1, 0, 1 };  // require space

bool IronManPath(int bX, int bY, int sX, int sY, int tX, int tY) {
       int newmap[N][N];

       for (int i = 0; i < N; i++) {
              for (int j = 0; j < N; j++) {
                     if (map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4) {
                           newmap[i][j] = 0;
                     }
                     else {
                           newmap[i][j] = map[i][j];
                     }
              }
       }
       newmap[sX][sY] = 2;
       newmap[bX][bY] = 1;
       newmap[tX][tY] = 4;

       // Is 2==>4 available?
       // BFS again
       queue<IronManPair> myQueue;
       for (int i = 0; i < N; i++) {
              for (int j = 0; j < N; j++) {
                     if (newmap[i][j] == 1) {
                           ironMandist[i][j] = NA;
                     }
                     else {
                           ironMandist[i][j] = Initial;
                     }
              }
       }
       myQueue.push(IronManPair(sX, sY));
       ironMandist[sX][sY] = 0;

       while (myQueue.size()) {
              IronManPair p = myQueue.front();
              myQueue.pop();

              if (p.first == tX && p.second == tY) {
                     return (true);
              }

              for (int i = 0; i < 4; i++) {
                     int next_x = p.first + dx[i], next_y = p.second + dy[i];
                     int req_x = p.first + rx[i], req_y = p.second + ry[i];

                     if ((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N)
                           && (newmap[next_x][next_y] != 1) && (ironMandist[next_x][next_y] == Initial)) {
                           myQueue.push(IronManPair(next_x, next_y));
                           ironMandist[next_x][next_y] = ironMandist[p.first][p.second] + 1;
                     }
              }
       }

       return (false);
}

void bfs() {
       queue<myPair> myQueue;

       for (int i = 0; i < N; i++) {
              for (int j = 0; j < N; j++) {
                     if (map[i][j] == 1) {
                           dist[i][j] = NA;
                           dist_Repeat[i][j] = Repeat;
                     }
                     else {
                           dist[i][j] = Initial;
                           dist_Repeat[i][j] = 0;
                     }
              }
       }

       myQueue.push(myPair(BoxPair(Sx, Sy), IronManPair(Ix, Iy)));
       dist[Sx][Sy] = 0;

       while (myQueue.size()) {
              myPair p = myQueue.front();
              myQueue.pop();

              if (p.first.first == Tx && p.first.second == Ty) {
                     return;
              }

              for (int i = 0; i < 4; i++) {
                     int next_x = p.first.first + dx[i], next_y = p.first.second + dy[i];
                     int req_x = p.first.first + rx[i], req_y = p.first.second + ry[i];

                     if ((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N)
                           && (map[next_x][next_y] != 1) && (map[req_x][req_y] != 1)
                           && (dist[next_x][next_y] <= Initial) && (dist_Repeat[next_x][next_y] <= Repeat)
                           && IronManPath(p.first.first, p.first.second, p.second.first, p.second.second, req_x, req_y)) {
                           myQueue.push(myPair(BoxPair(next_x, next_y), IronManPair(p.first.first, p.first.second)));
                           dist[next_x][next_y] = dist[p.first.first][p.first.second] + 1;
                           dist_Repeat[next_x][next_y]++;
                     }
              }
       }

       dist[Tx][Ty] = NA;
}

int main() {

       for (int i = 0; i < N; i++) {
              for (int j = 0; j < N; j++) {

                     cin >> map[i][j];

                     if (map[i][j] == 2) { // Where is IronMan 
                           Ix = i;
                           Iy = j;
                     }
                     else if (map[i][j] == 3) { // Where is the Box
                           Sx = i;
                           Sy = j;
                     }
                     else if (map[i][j] == 4) { // Where is the destination
                           Tx = i;
                           Ty = j;
                     }
              }
       }

       bfs();
       cout << dist[Tx][Ty] << endl;

       return 0;
}
