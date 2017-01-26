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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999
#define lim 1000010
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,h;

lli st[lim],end[lim],A[lim];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(h);

		for(lli i=0;i<n;i++) {
			st[i]=0;
			end[i]=0;
		}
		
		for(lli i=0;i<n;i++) {
			lli a,b;
			inp(a);
			inp(b);
			st[a]++;
			end[b]++;
		}


		lli ans=h*n;

		lli cur=n;
		lli val=0;
		for(lli i=0;i<h;i++) {
			cur-=st[i];
			val+=cur;
			A[i]=cur;
			cur+=end[i];
		}

		ans=min(ans,val);

		for(lli i=h;i<n;i++) {
			cur-=st[i];

			val+=cur;
			val-=A[i-h];
			A[i]=cur;
			ans=min(ans,val);

			cur+=end[i];
		}

		printf("%lld\n", ans);

	}

	return 0;
}