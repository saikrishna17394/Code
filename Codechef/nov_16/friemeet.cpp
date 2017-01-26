#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 50010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,long long int> ii;
typedef pair<double,int> di;

lli t, n, m;
vector<ii> g[lim];
lli A[lim] = {0}, B[lim] = {0};
lli num, den;
int vis[lim] = {0};

void dfs(int u, int par) {
	vis[u] = 1;
	B[u] = 0;
	if(A[u] == 1)
		B[u]++;

	for(int i = 0; i < g[u].size(); i++) {
		ii p = g[u][i];
		int v = p.first;
		if(vis[v] == 0) {
			dfs(v,u);
			B[u] += B[v];
			num += p.second*(m-B[v])*B[v];
		}
	}
}

lli gcd(lli a, lli b) {
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main() {
	cin >> t;

	while(t--) {
		cin >> n >> m;

		for(lli i = 1; i <= n; i++)
			g[i].clear();

		for(lli i = 1; i < n; i++) {
			int a,b;
			lli l;
			cin >> a >> b >> l;
			g[a].push_back(ii(b,l));
			g[b].push_back(ii(a,l));
		}
		
		memset(A, 0, sizeof A);
		for(lli i = 0; i < m; i++) {
			int a;
			cin >> a;
			A[a] = 1;
		}

		num = 0;
		den = m*m;

		memset(vis, 0, sizeof vis);
		memset(B, 0, sizeof B);

		dfs(1, -1);
		num *= 2;
		
		lli g = gcd(num, den);
		num /= g;
		den /= g;

		cout << num << " " << den << endl;
	}

	return 0;
}