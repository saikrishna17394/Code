#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli dp[40000];


lli solve(lli n) {
	if(n<40000)
		return dp[n];

	lli val=1;
	for(lli j=2;j*j<=n;j++) {
		if(n%j==0) {
			val=max(val,dp[j]);
			val=max(val,solve(n/j));
			break;
		}
	}
	return n+val;
}

int main() {
	dp[1]=1;
	dp[2]=3;

	for(lli i=3;i<40000;i++) {
		dp[i]=i;
		lli val=1;
		for(lli j=2;j*j<=i;j++) {
			if(i%j==0) {
				val=max(val,dp[j]);
				val=max(val,dp[i/j]);
			}
		}
		dp[i]+=val;
	}

	lli n;
	inp(n);

	if(n<40000) {
		printf("%lld\n", dp[n]);
	}
	else {
		printf("%lld\n", solve(n));

	}


	return 0;
}