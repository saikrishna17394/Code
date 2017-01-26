#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli dp[30];


int main() {
	// lli big=(lli)6227020800;
	// cout<<big<<endl;

	dp[0]=1;

	lli ans=14;

	for(lli i=1;i<30;i++) {
		dp[i]=i*dp[i-1];
		if(i>ans) {
			break;
		}
	}
	// cout<<ans<<endl;

	lli t,n;

	inp(t);

	while(t--) {
		inp(n);
		if(n>=ans) {
			printf("Overflow!\n");
			continue;
		}

		if(dp[n]<10000) {
			printf("Underflow!\n");
		}
		else {
			printf("%lld\n", dp[n]);
		}
	}
	return 0;
}