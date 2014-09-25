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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli pow1(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k&1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli dp[201][201];
int t,n,k,A[201],num;
int B[201];
lli fac[201],afac[201];

int main() {
	fac[0]=1;
	afac[0]=1;
	for(lli i=1;i<=200;i++) {
		fac[i]=(i*fac[i-1])%mod;
		afac[i]=pow1(fac[i],mod-2);
	}

	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		memset(A,0,sizeof A);
		for(int i=0;i<n;i++) {
			inp(num);
			A[num]++;
		}

		n=0;
		for(int i=1;i<=200;i++) {
			if(A[i])
				B[n++]=A[i];
		}
		dp[n-1][1]=fac[B[n-1]];
		// cout<<n-1<<" 1 "<<dp[n-1][1]<<endl;
		for(int j=2;j<=n;j++) {
			dp[n-1][j]=0;
			// cout<<n-1<<" "<<j<<" "<<dp[n-1][j]<<endl;
		}
		int rem=B[n-1];

		for(int i=n-2;i>=0;i--) {
			lli val1=B[i];
			val1=(val1*fac[rem+B[i]-1])%mod;
			val1=(val1*afac[rem])%mod;

			lli val2=rem;
			val2=(val2*fac[rem+B[i]-1])%mod;
			val2=(val2*afac[rem])%mod;

			dp[i][1]=(val2*dp[i+1][1])%mod;
			// cout<<i<<" 1 "<<dp[i][1]<<endl;
			for(int j=2;j<=n;j++) {
				dp[i][j]=(val1*dp[i+1][j-1])%mod;
				dp[i][j]=dp[i][j]+(val2*dp[i+1][j])%mod;
				dp[i][j]%=mod;
				// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}

			rem+=B[i];
		}

		lli ans=0;
		for(int i=1;i<=min(n,k);i++) {
			// cout<<n<<" "<<i<<" "<<dp[0][i]<<endl;
			ans=(ans+dp[0][i])%mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}