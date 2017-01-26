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

lli solve(lli n) {
	lli ret=n*(n-1);
	ret/=2;
	return ret;
}

int main() {
	lli t,n,A[200000],a,b,c;

	inp(t);

	while(t--) {
		inp(n);
		a=0;
		b=0;
		c=0;

		for(int i=0;i<n;i++) {
			inp(A[i]);
			if(A[i]==1)
				a++;
			else if(A[i]==2)
				b++;
			else
				c++;
		}
		lli ans=solve(a)*2;
		ans+=solve(b);
		ans+=a*c;
		ans+=a*b;
		printf("%lld\n", ans);
	}

	return 0;
}