#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


// int A[500*500];
vector<int> g[lim];
int A[lim],n;
int ans=0;

void dfs(int u,int par) {
	int val=0;
	for(int i=0;i<g[u].size();i++) {
		if(g[u][i]==par)
			continue;
		A[g[u][i]]+=A[u];
		dfs(g[u][i],u);
		val++;
	}

	if(val==0)
		ans=max(ans,A[u]);
}
int main(){ 
	// cin.sync_with_stdio(false);

	cin>>n;

	for(int i=1;i<=n;i++) {
		scanf("%d",&A[i]);
	}

	for(int i=2;i<=n;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}


	dfs(1,-1);

	printf("%d\n", ans);
	return 0;
}