#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


int n;
int sz[lim],dp[lim];
int h[lim][20];
vector<int> g[lim];


void dfs(int u)  {
	sz[u]=1;

	h[u][0]=1;

	for(int j=0;j<g[u].size();j++) {
		int v=g[u][j];

		if(sz[v]==0) {
			dfs(v);
			sz[u]+=sz[v];
			for(int k=0;k<19;k++) {
				h[u][k+1]+=h[v][k];
			}
		}
	}

	dp[u]=sz[u]-1;

	int val=sz[u];

	for(int k=0;k<20;k++) {
		val-=h[u][k];
		dp[u]=min(dp[u],val+((1<<(k+1))-(sz[u]-val)-1) );
	}

	// cout<<u<<" "<<dp[u]<<endl;
}
int main() {
	memset(sz,0,sizeof sz);
	memset(h,0,sizeof h);

	inp(n);

	for(int i=1;i<n;i++) {
		int a,b;
		inp(a);
		inp(b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);
	for(int i=0;i<n;i++) {
		if(i>0)
			printf(" ");
		printf("%d",dp[i] );
	}	
	printf("\n");
	return 0;
}