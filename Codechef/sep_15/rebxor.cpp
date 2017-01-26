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

#define mod 1000000009
#define inf 999999999
#define lim 400010

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
int A[lim],dp1[lim],dp2[lim];
int g[lim*30][2];
int sz=0;
int xor_val;

void push(int val) {
	int cur=0;

	for(int i=29;i>=0;i--) {
		int sgn=val/(1<<i);

		if(g[cur][sgn]==-1) {
			g[cur][sgn]=++sz;
			cur=sz;
		}
		else {
			cur=g[cur][sgn];
		}

		val%=(1<<i);
	}
}

int solve() {
	int cur=0;

	int ret=0;

	for(int i=29;i>=0;i--) {
		int sgn=xor_val&(1<<i);
		if(sgn>0)
			sgn=1;

		if(g[cur][sgn^1]!=-1) {
			cur=g[cur][sgn^1];
			ret|=(1<<i);
		}
		else {
			cur=g[cur][sgn];
		}
	}
	return ret;
}

int main() {
	inp(n);

	for(int i=0;i<n;i++)
		inp(A[i]);

	memset(g,-1,sizeof g);

	dp1[0]=A[0];
	push(A[0]);
	xor_val=0;

	for(int i=1;i<n;i++) {
		xor_val^=A[i];
		push(xor_val^A[i]);
		dp1[i]=max(dp1[i-1],solve());
		//cout<<i<<" "<<solve()<<endl;
	}

	memset(g,-1,sizeof g);

	dp2[n-1]=A[n-1];
	push(A[n-1]);
	xor_val=0;

	for(int i=n-2;i>=0;i--) {
		xor_val^=A[i];
		push(xor_val^A[i]);
		dp2[i]=max(dp2[i+1],solve());
	}

	int ans=0;

	for(int i=0;i<(n-1);i++) {
		ans=max(ans,dp1[i]+dp2[i+1]);
	}
	printf("%d\n", ans);
	return 0;
}