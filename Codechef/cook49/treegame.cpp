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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,m,level[10000],a,b,depth,vis[10001],ans;
vector<int> g[10001];

void dfs(int i,int d) {
	// cout<<"dfs"<<" "<<i<<" "<<d<<endl;
	vis[i]=1;
	level[d]++;
	depth=max(depth,d);
	for(int j=0;j<g[i].size();j++) {
		// cout<<"vis "<<g[i][j]<<" "<<vis[g[i][j]]<<endl;
		if(vis[g[i][j]]==0)
			dfs(g[i][j],d+1);
	}
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		// inp(m);

		for(int i=1;i<=n;i++)
			g[i].clear();

		for(int i=1;i<n;i++) {
			inp(a);
			inp(b);
			// cout<<a<<" df "<<b<<endl;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		depth=0;
		memset(vis,0,sizeof vis);
		dfs(1,0);

		ans=0;
		int l=0,r=depth;

		while(1) {
			// cout<<l<<" "<<r<<endl;
			ans++;
			l++;
			if(l>r)
				break;
			if(level[r]==0)
				r--;
			if(l>r)
				break;
			ans++;
			level[r]--;
			if(level[r]==0) {
				// break;
				r--;
			}
			if(l>r)
				break;
		}
		printf("%d\n", ans);
	}

	return 0;
}