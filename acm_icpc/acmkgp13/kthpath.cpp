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
lli n,q,vis[100001],sz[100001],a,b;
vector<lli> v[100001];

void dfs(lli i) {
	vis[i]=1;

	sz[i]=1;
	for(int j=0;j<v[i].size();j++) {
		if(vis[v[i][j]]==0) {
			dfs(v[i][j]);
			sz[i]+=sz[v[i][j]];
		}
	}
	return;
}

void dfs1(lli i,lli val) {
	printf("%lld ", i);
	vis[i]=1;

	if(val==0)
		return ;
	lli num=0;
	for(int j=0;j<v[i].size();j++) {
		if(vis[v[i][j]]==1)
			continue;
		num+=sz[v[i][j]];
		if(num>=val) {
			dfs1(v[i][j],val-num+sz[v[i][j]]-1);
			return;
		}
	}

}
int main() {
	lli t;

	inp(t);

	while(t--) {
		inp(n);
		inp(q);
		q--;

		for(int i=1;i<=n;i++)
			v[i].clear();

		for(int i=1;i<n;i++) {
			inp(a);
			inp(b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++) {
			sort(v[i].begin(),v[i].end());
			sz[i]=0;
			vis[i]=0;
		}

		dfs(q/n+1);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		dfs1(q/n+1,q%n);
		printf("\n");
	}

	return 0;
}