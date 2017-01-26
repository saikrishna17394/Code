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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,A[lim],dp[lim][2];

int main() {
	inp(t);


	while(t--) {
		inp(n);

		if(n==0) {
			printf("0\n");
			continue;
		}

		for(lli i=0;i<n;i++)
			inp(A[i]);

		dp[0][1]=A[0];
		dp[0][0]=0;

		for(lli i=1;i<n;i++) {
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);

			dp[i][1]=A[i]+dp[i-1][0];
		}

		printf("%lld\n", max(dp[n-1][0],dp[n-1][1]));
	}

	return 0;
}