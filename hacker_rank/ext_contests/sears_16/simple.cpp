#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<double,int> di;


int n,q,m,C;
vector<ii> A[50];
ii Q[lim];
int com[lim];
int ans[lim] = {0};

vector<int> B[lim];
int vis[lim],idx;

void dfs(int u,int v) {
	vis[u] = 1;
	com[u] = idx;

	for(int i = 0; i < B[u].size(); i++) {
		if(B[u][i] == v)
			continue;
		if(vis[B[u][i]] == 0)
			dfs(B[u][i],u);
	}
}


int main () {
	cin >> n >> m >> C;
	
	while(m -- ){
		int u,v,c;
		cin >> u >> v >> c;
		A[c].push_back(ii(u,v));
	}

	cin >> q;
	for(int i = 0; i < q; i++)
		cin >> Q[i].first >> Q[i].second;


	for(int i = 1; i<= C; i++) {
		for(int a = 1; a <= n; a++)
			B[a].clear();

		for(int j = 1; j <= C; j++) {
			if(i==j)
				continue;

			for(int a = 0; a < A[j].size();a++) {
				int x = A[j][a].first;
				int y = A[j][a].second;
				B[x].push_back(y);
				B[y].push_back(x);
			}
		}

		memset(vis,0,sizeof vis);
		idx = 1;
		for(int i = 1; i <= n; i++) {
			if(vis[i] == 0) {
				dfs(i,-1);
				idx++;
			}
		}

		for(int i = 0; i < q; i++) {
			if(com[Q[i].first] != com[Q[i].second])
				ans[i]++;
		}
	}

	for(int a = 1; a <= n; a++)
		B[a].clear();
	for(int j = 1; j<= C; j++) {
		for(int a = 0; a < A[j].size();a++) {
			int x = A[j][a].first;
			int y = A[j][a].second;
			B[x].push_back(y);
			B[y].push_back(x);
		}
	}

	memset(vis,0,sizeof vis);
	idx = 1;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			dfs(i,-1);
			idx++;
		}
	}

	for(int i = 0; i < q; i++) {
		if(com[Q[i].first] != com[Q[i].second])
			ans[i] = 0;
	}

	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}