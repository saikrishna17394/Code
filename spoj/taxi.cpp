// Solved using ford-fulkerson algorithm of augmenting paths
// Found the augmenting path by basic DFS.
// The prolbem also could have been solved by 
// maximum bipartite matching algorithm (which is more simple).

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
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli k,t,p,c,s,ans;
bool g[702][702],vis[702];
int par[702];

ii P[401],T[201];

bool check (int i,int j) {
	lli val=abs(P[i].first-T[j].first);
	val+=abs(P[i].second-T[j].second);
	val*=200;

	if((s*c)>=val)
		return true;
	return false;
}

bool dfs(int i) {
	vis[i]=1;

	if(g[i][t+p+1]) {
		par[t+p+1]=i;
		return true;
	}

	for(int j=1;j<=(t+p);j++) {
		if(g[i][j]==1 && vis[g[i][j]]==0) {
			par[g[i][j]]=i;
			if(dfs(g[i][j]))
				return true;
		}
	}

	return false;
}

int main() {

	inp(k);

	while(k--) {
		inp(p);
		inp(t);
		inp(s);
		inp(c);

		for(int i=1;i<=p;i++) {
			inp(P[i].first);
			inp(P[i].second);
		}
		for(int i=1;i<=t;i++) {
			inp(T[i].first);
			inp(T[i].second);
		}

		memset(g,0,sizeof g);

		for(int i=1;i<=p;i++) {
			for(int j=1;j<=t;j++) {
				if(check(i,j)) {
					g[i][j+p]=1;
				}
			}
		}

		for(int i=1;i<=p;i++)
			g[0][i]=1;

		for(int i=1;i<=t;i++)
			g[p+i][p+t+1]=1;

		ans=0;


		memset(vis,0,sizeof vis);

		while(dfs(0)) {
			int ver=t+p+1;
			while(ver>0) {
				g[par[ver]][ver]=0;
				g[ver][par[ver]]=1;
				ver=par[ver];
			}

			ans++;
			memset(vis,0,sizeof vis);
		}

		printf("%lld\n", ans);
	}


	return 0;
}


