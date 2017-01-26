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

#define mod 1008
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

lli t,n,A[1000],q,ans;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(lli i=0;i<n;i++)
			inp(A[i]);
		inp(q);
		ans=0;
		lli x=0;
		for(lli i=0;i<n;i++) {
			x+=A[i];
			if(x>=q) {
				ans+=(x-q);
				x=0;
			}
			// cout<<x<<" "<<A[i]<<" "<<q<<" "<<ans<<endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
}