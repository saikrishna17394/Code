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
#define lim 100001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,q,vis[lim],tim=0;
lli A[100001];
int tree[100001],st[100001],end[100001];
vector<int> g[100001];

void dfs(int i) {
	vis[i]=1;
	st[i]=++tim;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0)
			dfs(g[i][j]);
	}
	end[i]=tim;
}

void update(int idx,int val) {
	// cout<<idx<<" w "<<val<<endl;
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

int main() {
	inp(n);
	inp(q);

	int x,y,v;
	for(int i=1;i<n;i++) {
		inp(x);
		inp(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	memset(vis,0,sizeof vis);

	for(int i=1;i<=n;i++) {
		if(vis[i]==0)
			dfs(i);
	}

	for(int i=1;i<=n;i++) {
		scanf("%lld",&A[i]);
		if(A[i]==0) {
			update(st[i],1);	
		}
		// cout<<i<<" "<<A[i]<<" : "<<st[i]<<" "<<end[i]<<endl;
	}

	char c;
	while(q--) {
		cin>>c;
		if(c=='U') {
			inp(x);
			inp(v);
			
			if(A[x]==0)
				update(st[x],-1);
			A[x]+=v;
			if(A[x]==0)
				update(st[x],1);			
		}
		else {
			inp(x);
			printf("%d\n", read(end[x])-read(st[x]-1));
		}
	}

	return 0;
}