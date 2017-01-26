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

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli fac[100010],dp[100010];

lli t,n;

int main( ) {
	inp(t);

	fac[0]=1;
	dp[0]=0;
	for(lli i=1;i<(lli)100010;i++) {
		fac[i]=(i*fac[i-1])%mod;
		dp[i]=(i*(i+1))/2;
		dp[i]%=mod;
	}


	while(t--) {
		inp(n);

		lli ans=0;

		for(lli i=1;i<=n;i++) {
			ans+=dp[n-i]+dp[i-1];
			ans%=mod;
			// cout<<ans<<endl;
		}

		// cout<<ans<<endl;
		ans=(ans*fac[n-1])%mod;

		cout<<ans<<endl;
	}

	return 0;
}