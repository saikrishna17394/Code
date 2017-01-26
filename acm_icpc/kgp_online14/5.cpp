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
lli t,n,k;

lli power(lli n,lli k) {
	lli ret=1;

	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli afac[200001];
lli fac[200001];

lli ncr(lli n,lli k) {
	lli ret=(fac[n]*afac[k])%mod;
	ret=(ret*afac[n-k])%mod;
	// cout<<n<<" "<<k<<" "<<ret<<endl;
	return ret;
}

int main() {
	inp(t);

	afac[0]=1;
	afac[1]=1;
	fac[1]=1;
	fac[0]=1;

	// cout<<fac[1]<<endl;
	for(lli i=2;i<(lli)200001;i++) {
		// cout<<i<<" "<<fac[i-1]<<endl;
		fac[i]=(fac[i-1]*i)%mod;
		afac[i]=power(fac[i],mod-2);
		// if(i<10)
		// 	cout<<i<<" "<<fac[i-1]<<" "<<afac[i]<<endl;
	}

	while(t--) {
		inp(n);
		inp(k);

		if(n==1) {
			printf("-1\n");
			continue;
		}

		lli ans=0;

		for(lli i=1;i*i<=k;i++) {
			ans+=ncr(n-2+i-1,i-1)*(k/i-(i-1));
		}
		printf("%lld\n", ans);
	}


	return 0;
}