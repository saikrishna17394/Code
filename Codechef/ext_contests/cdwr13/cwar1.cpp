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
#define lim 10000001
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli pow1(lli n,lli k) {
	lli ans=1,num=n;
	// cout<<n<<"  sa "<<k<<endl;
	while(k) {
		// cout<<n<<" "<<k<<endl;
		if(k&1)
			ans=(ans*num)%mod;
		num=(num*num)%mod;
		k>>=1;
	}
	return ans;
}

int main() {
	lli A[17],fac[17],t,n,k,ans,ans1;

	fac[0]=1;
	A[0]=1;

	for(lli i=1;i<17;i++) {
		fac[i]=(i*fac[i-1])%mod;
		A[i]=pow1(fac[i],mod-2);
		// cout<<i<<" "<<fac[i]<<" "<<A[i]<<endl;
	}
	inp(t);
	while(t--) {
		inp(n);
		inp(k);

		ans=1;

		for(lli i=0;i<k;i++) {
			ans=(ans*(n-i))%mod;
			// cout<<ans<<" "<<n-i<<endl;
		}
		// cout<<A[2]<<endl;
		ans=(ans*A[k])%mod;

		if(k>1) {
			ans1=1;
			n--;
			k-=2;
			for(lli i=0;i<k;i++) {
				ans1=(ans1*(n-i))%mod;
				// cout<<ans<<" "<<n-i<<endl;
			}
			// cout<<A[2]<<endl;
			ans1=(ans1*A[k])%mod;
			ans=(ans+ans1)%mod;
		}


		printf("%lld\n", ans);
	}
	return 0;
}