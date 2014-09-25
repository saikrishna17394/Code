#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}
int t,n,m,par[100001],sz[100001],a,b;

int root(int n) {
	if(par[n]==n)
		return n;
	par[n]=root(par[n]);
	return par[n];
}

void unio(int a,int b) {
	if(sz[a]>=sz[b]) {
		par[b]=a;
		sz[a]+=sz[b];
	}
	else {
		par[a]=b;
		sz[b]+=sz[a];
	}
}

int ans,num;
int main() {

	inp(t);
	while(t--) {
		inp(n);
		inp(m);

		for(int i=1;i<=n;i++) {
			par[i]=i;
			sz[i]=1;
		}

		while(m--) {
			inp(a);
			inp(b);

			a=root(a);
			b=root(b);

			if(a!=b)
				unio(a,b);
		}

		ans=0;
		num=-1;

		for(int i=1;i<=n;i++) {
			if(par[i]==i) {
				if(sz[i]&1)
					num=max(num,sz[i]);
				else
					ans+=sz[i];
			}
		}

		ans+=num+1;

		printf("%d\n",ans);

	}
	return 0;
}
