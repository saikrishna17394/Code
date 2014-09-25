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

lli t,x;

int main() {
	inp(t);

	while(t--) {
		lli l=1,r=1e6;

		inp(x);
		while(l<r) {
			lli mid=(l+r)/2;
			mid++;
			lli val=mid*(mid+1)*(2*mid+1);
			val/=6;
			if(val>x)
				r=mid-1;
			else
				l=mid;
		}
		printf("%lld\n", l);
	}


	return 0;
}