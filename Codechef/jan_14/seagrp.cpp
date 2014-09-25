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
int t,n,m,g[101][101],a,b,ans,match[101],vis[101];

bool dfs(int i) {

	for(int j=1;j<=n;j++) {
		if(vis[j] || g[i][j]==0)
			continue;
		vis[j]=1;
		if(match[j]==-1 || dfs(match[j])) {
			match[j]=i;
			return true;
		}
	}
	return false;
}
int main() {
	inp(t);
	while(t--) {
		inp(n);
		inp(m);
		memset(g,0,sizeof g);
		while(m--) {
			inp(a);
			inp(b);
			g[min(a,b)][max(a,b)]=1;
			// g[b][a]=1;
		}
		if(n&1) {
			printf("NO\n");
			continue;
		}
		ans=0;
		memset(match,-1,sizeof match);

		for(int i=1;i<=n;i++) {
			memset(vis,0,sizeof vis);
			if(dfs(i))
				ans++;
		}
		if(ans==(n/2))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}