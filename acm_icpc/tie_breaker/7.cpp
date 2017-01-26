#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,int> di;

using namespace std;

int t,n,m;

struct node{
	lli a,b;
	double r;
	double diff;
};

node v[100000];

bool compare(node l, node r) {
	if (l.diff < r.diff) return true;
	if (l.diff > r.diff) return false;
	return (l.b > r.b);
}

lli gcd(lli a, lli b) {
	if (b == 0) return a;
	if (a == 0) return b;
	return gcd(b, a%b);
}

int main() {
	cin>>t;

	while(t--) {
		cin>>n>>m;
		double maxr = -1.0;
		lli a1=0,a2=1;

		for(int i=0;i<n;i++) {
			cin>>v[i].a>>v[i].b;
			lli temp = (v[i].a*a2-v[i].b*a1);
			if (temp > 0) {
				a1 = v[i].a;
				a2 = v[i].b;
			}
			if (temp == 0) {
				if (v[i].b > a2) {
					a1 = v[i].a;
					a2 = v[i].b;
				}
			}
			lli g = gcd(v[i].a, v[i].b);
			v[i].r = ((double)(v[i].a/g))/((double)(v[i].b/g));
			maxr = max(maxr, v[i].r);
		}

		for (int i=0; i<n; i++) {
			v[i].diff = ((maxr - v[i].r)*(v[i].b))/((double)(v[i].b + a2));
		}
		sort(v,v+n,compare);

		double ans = 0.0;
		lli asum = 0, bsum = 0;
		for (int i=0; i<m; i++) {
			asum += v[i].a;
			bsum += v[i].b;
		}
		ans = ((double)asum)/((double)bsum);
		printf("%.6f\n",ans);
	}
	return 0;
}