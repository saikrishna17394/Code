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

lli power(lli n,lli k,lli m) {
	lli ret=1;
	n%=m;
	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%m;
		n=(n*n)%m;
		k/=2;
	}
	return ret;
}

lli sum(lli n) {
	lli ret=0;
	while(n>0) {
		ret+=n%2;
		n/=2;
	}
	return ret;
}

lli t,n;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		
		printf("%lld\n", power(2,(n*sum(n))%(mod-1),mod));
	}

	return 0;
}