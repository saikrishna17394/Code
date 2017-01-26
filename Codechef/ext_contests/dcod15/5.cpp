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

int n,q;
int par[lim],sz[lim];

int root(int u) {
	if(par[u]==u)
		return u;
	return par[u]=root(par[u]);
}

void join(int u,int v) {
	if(sz[u]>=sz[v]) {
		sz[u]+=sz[v];
		par[v]=u;
	}
	else {
		sz[v]+=sz[u];
		par[u]=v;
	}
}

int main() {

	inp(n);
	inp(q);

	for(int i=1;i<=n;i++) {
		par[i]=i;
		sz[i]=1;
	}

	while(q--) {
		int a,x,y;
		inp(a);
		inp(x);
		inp(y);

		x=root(x);
		y=root(y);
		if(a==0) {
			join(x,y);
		}
		else {
			if(x!=y)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}