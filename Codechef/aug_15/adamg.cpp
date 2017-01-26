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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		lli l=1,r=mod;
		r*=2;

		while(l<r) {
			lli m=(l+r)/2;

			lli val;

			if(m%2==1) {
				val=(m+1)/2;
				val*=val;
			}
			else {
				val=m*(m+2);
				val/=4;
			}
			if(val>=n)
				r=m;
			else
				l=m+1;
		}
		printf("%lld\n",l);
	}

	return 0;
}