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
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
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
lli dp[1001][1001],fac[1001],afac[1001];
lli pow1(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k&1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k>>=1;
	}
	return ret;
}
lli solve(int n,int m) {
	if(n>m)
		return 0;
	if(n==0) {
		// cout<<n<<" "<<m<<" 1"<<endl;
		return 1;
	}
	if(n==1) {
		lli val=m-n;
		// val*=(val-1);
		// cout<<n<<" "<<m<<" "<<val<<endl;		
		return val;
	}
	lli& ret=dp[n][m];
	if(ret!=-1)
		return ret;
	ret=0;
	if(m>n)
		ret+=(lli)(m-n)*solve(n-1,m-1);
	ret%=mod;


		ret+=(lli)(n-1)*solve(n-2,m-2);
		ret%=mod;
	// lli val=solve(n-2,m-2);

	ret+=(lli)(n-1)*solve(n-1,m-1);
	// val%=mod;
	// ret+=(lli)(n-1)*val;
	ret%=mod;
	// cout<<n<<" "<<m<<" "<<ret<<endl;
	return ret;
}

int main() {
	int t,n,m;
	inp(t);
	fac[0]=1;
	afac[0]=1;

	for(lli i=1;i<1001;i++) {
		fac[i]=(i*fac[i-1])%mod;
		afac[i]=pow1(fac[i],mod-2);
	}
	memset(dp,-1,sizeof dp);
	while(t--) {
		inp(n);
		inp(m);
		lli val=0;
		if(m>=n)
			val=(fac[m]*afac[m-n])%mod;
		printf("%lld\n",(val*solve(n,m))%mod);
	}

	return 0;
}