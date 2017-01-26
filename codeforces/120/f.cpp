#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int t,n;
vector<int> g[101];
int ht[101],vis[101],ans[101];

void dfs(int u) {
	vis[u]=1;
	ht[u]=0;
	ans[u]=0;

	int val=0;

	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(vis[v]==0) {
			dfs(v);
			ans[u]=max(ans[u],ans[v]);
			ans[u]=max(ans[u],ht[v]+ht[u]+1);
			ht[u]=max(ht[u],ht[v]+1);
		}
	}
}

int main(){ 
	// cin.sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin>>t;

	int val=0;
	while(t--) {
		cin>>n;

		for(int i=1;i<=n;i++)
			g[i].clear();

		for(int i=1;i<n;i++) {
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		memset(vis,0,sizeof vis);
		
		dfs(1);
		val+=ans[1];
	
	}

	cout<<val<<endl;

	return 0;
}