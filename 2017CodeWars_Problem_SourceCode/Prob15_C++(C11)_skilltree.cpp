#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;

map<string, int> id; 

vector<int> g[100005];
int cst[100005];
bool v[100005];

int main() {
	int n, m, cnt = 0; string a, b, sub;
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		cin >> sub >> cst[i];
		id[sub] = i;
	}
	for(int i = 0;i < m;i++) {
		cin >> a >> b;
		g[id[b]].push_back(id[a]); 
	}
	cin >> sub;
	int st = id[sub], ans;
	ans = cst[st]; v[st] = true;
	queue<int> q; q.push(st);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(auto y: g[x]) {
			if(v[y]) continue;
			v[y] = true;
			ans += cst[y];
			q.push(y);
		}
	}
	printf("%d\n", ans);	
}