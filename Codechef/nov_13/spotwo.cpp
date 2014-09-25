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
#define lli unsigned long long int
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
lli pow1(lli n,lli k) {
	lli ans=1;
	while(k) {
		if(k&1)
			ans=(ans*n)%mod;
		n=(n*n)%mod;
		k>>=1;
	}
	return ans;
}
lli conv(lli n) {
	lli ret=0,po=1;
	while(n) {
		if(n&1)
			ret+=po;
		n>>=1;
		po*=10;
	}
	return ret;
}
int main() {
	lli t,n,val,ans;

	inp(t);

	while(t--) {
		inp(n);
		
		val=conv(n);
		ans=pow1(2,val);
		ans=(ans*ans)%mod;

		printf("%lld\n", ans);
	}

	return 0;
}