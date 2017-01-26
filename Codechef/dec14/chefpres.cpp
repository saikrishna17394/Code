#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int n,k,b,q;
vector<int> g[10001];

int dp[10001][101];
int F[10001],par[10001];

void dfs(int u,int dad) {
	par[u]=dad;

	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(v==dad)
			continue;
		dfs(v,u);
		for(int j=1;j<=k;j++) {
			int val=min(dp[u][j],dp[v][j]);
			if(val!=-1)
				dp[u][j]=val;
			else
				dp[u][j]=max(dp[u][j],dp[v][j]);
		}
	}
}

int main() {
	cin>>n>>k>>b;

	memset(dp,-1,sizeof dp);

	for(int i=1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i=1;i<=n;i++) {
		cin>>F[i];
		dp[i][F[i]]=i;
	}

	dfs(b,-1);

	cin>>q;

	int a,p;

	while(q--) {
		cin>>a>>p;

		while(a!=-1) {
			if(dp[a][p]!=-1)
				break;
			a=par[a];
		}
		if(a==-1)
			printf("%d\n",a);
		else
			printf("%d\n", dp[a][p]);
	}
	return 0;
}