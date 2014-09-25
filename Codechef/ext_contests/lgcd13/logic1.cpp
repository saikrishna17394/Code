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
#define lim 10000001
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli t,n,k;

lli ans(lli a,lli b) {
	// cout<<a<<" "<<b<<endl;
	if(a==b)
		return a;
	lli mid=(a+b)/2;
	// cout<<mid<<endl;
	lli val=(mid*(mid+1))/2;
	// cout<<mid<<" "<<nendl;
	if(val>=n)
		return ans(a,mid);
	return ans(mid+1,b);
}

int main() {

	inp(t);

	while(t--) {
		inp(n);
		// if(n==1)
		// 	printf("0\n");
		// else
		if(n==1) {
			printf("0\n");
			continue;
		}
		// if(n<=3) {
		// 	printf("2\n");
		// 	continue;
		// }
		// cout<<n<<endl;
		// k=sqrt(n);
		// ans=n/k;
		// // cout<<ans<<" "<<k<<endl;
		// ans=ans+sqrt(n)-1;
		// k++;
		// ans=min(ans,n/k+k-1);
		printf("%lld\n", ans(1,n));
	}

	return 0;
}