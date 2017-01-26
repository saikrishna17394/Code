#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

int ans=0;
int n,m;
vector<int> g[lim];
int dp[lim],tot[lim],A[lim],vis[lim]={0};

void dfs(int u,int par) {
	if(par==-1) {
		if(A[u]==0)
			dp[u]=0;
		else
			dp[u]=1;
		tot[u]=dp[u];
	}
	else {
		if(A[u]==0)
			dp[u]=0;
		else
			dp[u]=dp[par]+1;
		tot[u]=max(dp[u],tot[par]);
	}

	int val=0;
	for(int i=0;i<g[u].size();i++) {
		if(g[u][i]==par)
			continue;
		val++;
		dfs(g[u][i],u);
	}

	if(val==0) {
		if(tot[u]<=m)
			ans++;
	}
}

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n>>m;

	for(int i=1;i<=n;i++) 
		scanf("%d",&A[i]);

	for(int i=1;i<n;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1,-1);

	cout<<ans<<endl;
	return 0;
}