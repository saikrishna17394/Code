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
#define inf (lli)1e16

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,k,a,b;
vector<ii> g[100001],g1[100001];
int vis[100001],cnt[100001];

lli B[100001],ans;
int idx=0;

void dfs(int u) {
	vis[u]=1;
	cnt[u]=1;

	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i].first;
		if(vis[v]==1)
			continue;
		dfs(v);
		ans+=(lli)( ((lli)g1[u][i].second*(lli)(n-cnt[v]))*(lli)cnt[v]);
		B[idx++]=(lli)( ((lli)g[u][i].second*(lli)(n-cnt[v]))*(lli)cnt[v]);

		// cout<<u<<" "<<v<<" "<<cnt[v]<<endl;
		// cout<<B[idx-1]<<" "<<ans<<endl<<endl;
		cnt[u]+=cnt[v];
	}
}


int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);

		for(int i=1;i<=n;i++) {
			g[i].clear();
			g1[i].clear();
		}

		for(int i=1;i<n;i++) {
			int x,y;
			inp(a);
			inp(b);
			inp(x);
			inp(y);
			g[a].push_back(ii(b,max(x-y,0)));
			g[b].push_back(ii(a,max(x-y,0)));

			g1[a].push_back(ii(b,x));
			g1[b].push_back(ii(a,x));

		}

		memset(vis,0,sizeof vis);

		idx=0;
		ans=0;
		dfs(1);


		sort(B,B+idx);

		for(int i=0;i<k;i++) {
			ans-=B[n-i-2];
		}
		cout<<ans<<endl;
	}


	return 0;
}