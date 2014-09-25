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
#define ii pair<int,char>

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,A[lim],dp[lim],dp1[lim],ans,k;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		for(int i=0;i<n;i++)
			inp(A[i]);
		dp[0]=A[0];
		for(int i=1;i<n;i++)
			dp[i]=max(A[i],dp[i-1]+A[i]);

		dp1[n-1]=A[n-1];
		for(int i=n-2;i>=0;i--)
			dp1[i]=max(A[i],dp1[i+1]+A[i]);

		for(int i=n-2;i>=0;i--)
			dp1[i]=max(dp1[i],dp1[i+1]);

		ans=(lli)-1e16;

		for(int i=0;(i+k+1)<n;i++) {
			ans=max(ans,dp[i]+dp1[i+k+1]);
		}

		printf("%lld\n", ans);

	}


	return 0;
}