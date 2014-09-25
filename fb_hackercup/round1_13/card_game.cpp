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
#define mp make_pair
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

lli pow1(lli x,lli n) {
	lli ret=1;
	while(n) {
		if(n&1)
			ret=(ret*x)%mod;
		n>>=1;
		x=(x*x)%mod;
	}
	return ret;
}

int main() {
	lli t,n,A[10000],k,ans,val;
	inp(t);

	for(lli a=1;a<=t;a++) {
		inp(n);
		inp(k);
		for(lli i=0;i<n;i++)
			inp(A[i]);
		sort(A,A+n);
		ans=A[k-1];
		val=1;

		for(lli i=k;i<n;i++) {
			val=(val*i)%mod;
			val=(val*pow1(i-k+1,mod-2))%mod;
			ans=(ans+val*A[i])%mod;
		}

		printf("Case #%lld: %lld\n",a,ans);
	}


	return 0;
}