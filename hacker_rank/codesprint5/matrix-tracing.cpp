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

lli pow(lli n, lli k) {
	lli ret=1;
	while(k) {
		if(k&1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli fac[2000000],afac[2000000],ans;

int main() {
	fac[0]=1;
	afac[0]=1;

	for(lli i=1;i<2000000;i++) {
		fac[i]=(i*fac[i-1])%mod;
		afac[i]=pow(fac[i],(lli)(mod-2));
	}

	int t,m,n;
	inp(t);

	while(t--) {
		inp(m);
		inp(n);
		m--;
		n--;

		ans=(fac[m+n]*afac[m])%mod;
		ans=(ans*afac[n])%mod;
		printf("%lld\n", ans);
	}

	return 0;
}