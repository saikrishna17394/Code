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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli dp[13][100];

lli ans(int n,int k) {
	if(k>(n*(n-1))/2)
		return 0;
	if(n==1)
		return 1;

	if(dp[n][k]!=-1)
		return dp[n][k];
	lli num=0;

	for(int i=0;i<n;i++) {
		if(i>k)
			break;
		num+=ans(n-1,k-i);
	}
	dp[n][k]=num;
	return num;
}

int main() {
	int t,n,k;
	memset(dp,-1,sizeof dp);
	inp(t);

	while(t--) {
		inp(n);
		inp(k);

		printf("%lld\n", ans(n,k));
	}

	return 0;
}