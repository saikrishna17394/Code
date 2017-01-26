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
lli A[10000],dp[10000];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);

		for(lli i=0;i<n;i++)
			inp(A[i]);

		set<lli> s;
		dp[0]=A[0];
		lli ans=dp[0];

		for(lli i=1;i<n;i++) {
			if((i-k-1)>=0)
				s.insert(dp[i-k-1]);
			dp[i]=A[i];
			if(!s.empty()) {
				dp[i]=max(dp[i],A[i]+(*s.rbegin()));
			}
			ans=max(ans,dp[i]);
		}
		ans=max(ans,(lli)0);
		printf("%lld\n", ans);
	}

	return 0;
}