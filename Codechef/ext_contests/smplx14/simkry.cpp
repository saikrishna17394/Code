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

bool check(lli n) {
	for(lli i=2;i*i<=n;i++)
		if(n%i==0)
			return false;

	return true;
}

lli power(lli n,lli k) {
	lli ret=1;
	n%=mod;
	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%mod;
		k/=2;
		n=(n*n)%mod;
	}
	return ret;
}

lli dp[100001],q,a,b;

int main() {
	dp[0]=1;

	dp[1]=1;
	dp[2]=2;

	for(lli i=3;i<100001;i++) {
		dp[i]=dp[i-1];
		if(check(i))
			dp[i]=(dp[i-1]*i)%mod;
	}

	inp(q);

	while(q--) {
		inp(a);
		inp(b);
		printf("%lld\n", (dp[b]*power(dp[a-1],mod-2))%mod);
	}

	return 0;
}