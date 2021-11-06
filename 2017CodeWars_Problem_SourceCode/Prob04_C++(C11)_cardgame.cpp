#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

vector<pii> v, vv[2];
set<pii> s;

int main() {
	int n; scanf("%d", &n);
	v.resize(n);
	for(int i = 0;i < n;i++) scanf("%d", &v[i].first);
	for(int i = 0;i < n;i++) scanf("%d", &v[i].second);
	for(auto e: v) s.insert(e);
	vv[0] = v; vv[1] = v;
	for(int i = 0;i < n;i++) swap(vv[1][i].first, vv[1][i].second);
	sort(vv[0].begin(), vv[0].end());
	sort(vv[1].begin(), vv[1].end());
	for(int i = 0;i < n;i++) swap(vv[1][i].first, vv[1][i].second);
	bool first = false;
	while(!first and vv[0].size() and vv[1].size()) {
		while(vv[0].size() and s.count(vv[0].back()) == 0) vv[0].pop_back();
		while(vv[1].size() and s.count(vv[1].back()) == 0) vv[1].pop_back();
		if(vv[0].size() == 0 or vv[1].size() == 0) break;
		if(vv[0].back() == vv[1].back()) 
			first = true;
		else {
			int x = vv[0].back().first;
			while(vv[0].back().first == x) s.erase(vv[0].back()), vv[0].pop_back();
			x = vv[1].back().second;
			while(vv[1].back().second == x) s.erase(vv[1].back()), vv[1].pop_back();
		}
	}
	puts(first? "A": "B");
}