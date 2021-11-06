#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const double eps = 1e-8;

typedef pair<int, int> pii;
vector<pii> in;

int main() {
	int n; scanf("%d", &n);
	in.resize(n);
	for(int i = 0;i < n;i++) scanf("%d", &in[i].first);
	for(int i = 0;i < n;i++) scanf("%d", &in[i].second);
	sort(in.begin(), in.end());
	double r = 1e9, l = 0;
	while(r - l > eps) {
		double m = (r + l) / 2, ll, rr;
		//printf("%lf %lf %lf\n", l, m, r);
		ll = in[0].first - in[0].second * m;
		rr = in[0].first + in[0].second * m;
		for(int i = 1;i < n;i++)
			ll = max(ll, in[i].first - in[i].second * m), rr = min(rr, in[i].first + in[i].second * m);
		if(rr - ll > eps) r = m;
		else l = m;
	}
	printf("%.6f\n", l);
}