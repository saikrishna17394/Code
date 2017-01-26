#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int n,t;
int nxt[300000];
int vis[300000];

bool dfs(int i) {
	if(i==t)
		return true;
	vis[i]=1;

	if(nxt[i]==-1 || vis[nxt[i]]==1)
		return false;
	return dfs(nxt[i]);
}

int main(){ 
	cin>>n>>t;	
	
	for(int i=1;i<n;i++) {
		cin>>nxt[i];
		nxt[i]+=i;
	}

	nxt[n]=-1;
	memset(vis,0,sizeof vis);

	if(dfs(1))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}