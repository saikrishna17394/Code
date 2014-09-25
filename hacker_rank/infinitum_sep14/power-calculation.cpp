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

#define mod 100
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

lli pow1(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli t,k,n,A[100];

int main() {
	inp(t);

	while(t--) {
		inp(k);
		inp(n);

		lli ans=0;

		for(lli i=0;i<mod;i++) {
			A[i]=pow1(i,n);
			ans+=A[i];
		}
		ans%=mod;
		ans*=(k/mod);
		ans%=mod;

		for(lli i=0;i<=(k%mod);i++)
			ans+=A[i];
		ans%=mod;
		if(ans<10)
			printf("0%lld\n", ans);
		else
			printf("%lld\n", ans);
	}


	return 0;
}