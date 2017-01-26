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


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli dp[1<<15][16][16];
lli n;

lli solve(lli msk,lli k,lli prev) {
	lli& ret=dp[msk][k][prev];

	if(ret!=-1)
		return ret;

	if(msk==0) {
		ret=1;
		return ret;
	}

	ret=0;

	lli mask=msk;
	for(lli i=0;i<n;i++) {
		if(mask%2==1) {
			if(prev==0)
				ret+=solve(msk^(1<<i),k,i+1);
			else if(abs(prev-i-1)<=k)
				ret+=solve(msk^(1<<i),k,i+1);
			else
				;
		}
		mask/=2;
	}
	return ret;
}

lli t,k;
int main() {
	inp(t);

	memset(dp,-1,sizeof dp);

	while(t--) {
		inp(n);
		inp(k);
		printf("%lld\n", solve((1<<n)-1,k,(lli)0));
	}

	return 0;
}