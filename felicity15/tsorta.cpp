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
int t,p,q,r;
int A[lim],B[lim],C[lim];
lli dp[lim];
lli dp1[lim];

lli solve(int idx,int val) {
	int l=0,r=idx;

	while(l<r) {
		int m=(l+r)/2;

		if(A[m+1]<=val)
			l=m+1;
		else
			r=m;
	}

	if(A[l]<=val)
		return (lli)(l+1);
	return (lli)l;
}

lli solve1(int idx,int val) {
	int l=0,r=idx;

	while(l<r) {
		int m=(l+r)/2;

		if(B[m+1]<=val)
			l=m+1;
		else
			r=m;
	}

	if(B[l]<=val)
		return dp[l];
	return (lli)0;
}

int main() {
	inp(t);

	while(t--) {
		memset(dp,0,sizeof dp);
		memset(dp1,0,sizeof dp1);

		inp(p);
		for(int i=0;i<p;i++)
			inp(A[i]);

		inp(q);
		for(int i=0;i<q;i++)
			inp(B[i]);

		inp(r);
		for(int i=0;i<r;i++)
			inp(C[i]);

		dp[0]=solve(0,B[0]);

		for(int i=1;i<q;i++) {
			dp[i]=dp[i-1];

			dp[i]+=solve(min(i,p-1),B[i]);
		}

		for(int i=0;i<r;i++) {
			if(i>0)
				dp1[i]=dp1[i-1];
			dp1[i]+=solve1(min(i,q-1),C[i]);
		}

		printf("%lld\n", dp1[r-1]);
	}

	return 0;
}