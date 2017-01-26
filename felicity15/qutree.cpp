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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16
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

int n,m,k;
lli tree[lim];


vector<int> g[lim];
int h[lim];
vector<int> v[lim];

void upd(int idx,int val) {
	while(idx<lim) {
		tree[idx]+=(lli)val;
		idx+=idx&-idx;
	}
}

lli read(int idx) {
	lli ret=0;
	while(idx>0) {
		ret+=tree[idx];
		idx-=idx&-idx;
	}
	return ret;
}

int tim=0;
int st[lim],end[lim],ref[lim];

void dfs(int u,int par) {
	st[u]=++tim;
	ref[tim-1]=u;

	if(par!=-1) {
		h[u]=h[par]+1;
		v[h[u]].push_back(u);
	}

	for(int i=0;i<g[u].size();i++) {
		if(g[u][i]!=par)
			dfs(g[u][i],u);
	}

	end[u]=tim;
}

int dp[400][lim];
lli inc[lim]={0};

int main() {
	inp(n);
	inp(m);

	h[1]=0;
	v[0].push_back(1);

	for(int i=1;i<n;i++) {
		int u,z;
		inp(u);
		inp(z);

		g[u].push_back(z);
		g[z].push_back(u);
	}

	dfs(1,-1);

	k=sqrt(n);

	int a,l,x;

	vector<int> v1;

	for(int i=0;i<lim;i++) {
		if(v[i].size()>k)
			v1.push_back(i);
		inc[i]=0;
	}

	for(int i=0;i<v1.size();i++) {
		dp[i][0]=0;

		for(int j=1;j<=n;j++) {
			dp[i][j]=dp[i][j-1];
			if(h[ref[j]]==v1[i])
				dp[i][j]++;
		}
	}

	memset(tree,0,sizeof tree);
	memset(inc,0,sizeof inc);

	while(m--) {
		inp(a);

		if(a==1) {
			inp(l);
			inp(x);

			if(v[l].size()<=k) {
				for(int i=0;i<v[l].size();i++) {
					upd(st[v[l][i]],x);
				}
			}
			else {
				inc[l]+=(lli)x;
			}
		}
		else {
			inp(x);

			lli ans=read(end[x])-read(st[x]-1);

			for(int i=0;i<v1.size();i++) {
				lli val1=(lli)(dp[i][end[x]]-dp[i][st[x]-1]);
				ans+=val1*inc[v1[i]];
			}
			printf("%lld\n", ans);
		}
	}

	return 0;
}