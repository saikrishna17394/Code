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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli num_of_digits(lli n) {
	lli val=0;

	while(n) {
		val++;
		n/=10;
	}
	return val;
}

lli ans(lli l,lli r) {
	lli num1=num_of_digits(l);
	lli num2=num_of_digits(r);

	lli val=0;

	if(num1==num2) {
		val=(r*(r+1))/2;
		val-=(l*(l-1))/2;

		val%=mod;

		val=(val*num1)%mod;
		return val;
	}

	lli mid=1;

	for(int i=1;i<num2;i++) {
		mid*=10;
	}

	return (ans(l,mid-1)+ans(mid,r))%mod;
}

int main() {
	lli t,l,r;

	inp(t);

	while(t--) {
		inp(l);
		inp(r);

		printf("%lld\n", ans(l,r));
	}

	return 0;
}
