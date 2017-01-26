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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n;
lli A[100000], dp[100000][2];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			inp(A[i]);

		dp[0][0]=A[0];
		dp[0][1]=A[0];

		lli ans= A[0];


		dp[1][0]=max(A[1],A[0]+A[1]);
		dp[1][1]=dp[1][0];

		ans = max(ans,dp[1][0]);

		for(int i=2;i<n;i++) {
			dp[i][0]=max(A[i],A[i]+dp[i-1][0]);
			dp[i][1]=max(A[i],A[i]+dp[i-2][0]);
			ans=max(ans,dp[i][0]);
			ans=max(ans,dp[i][1]);
		}

		printf("%lld\n", ans);
	}
	return 0;
}
