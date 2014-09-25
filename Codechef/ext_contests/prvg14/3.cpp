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
lli t,n,ans,dp[30001];
ii A[30000];

int bin(int i,ii num) {

	int l=i+1,r=n-1,mid;
	lli val=num.second;

	while(l<=r) {
		if(l==r) {
			if(A[l].first>val)
				return l;
			return l+1;
		}
		mid=(l+r)/2;

		if(A[mid].first>val) {
			r=mid;
		}
		else
			l=mid+1;
	}
}

int main() {

	inp(t);


	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}
		sort(A,A+n);

		dp[n-1]=A[n-1].second-A[n-1].first+1;
		dp[n]=0;

		for(int i=n-2;i>=0;i--) {
			dp[i]=max(dp[i+1],A[i].second-A[i].first+1+dp[bin(i,A[i])]);
		}
		ans=0;

		for(int i=0;i<n;i++)
			ans=max(ans,dp[i]);
		printf("%lld\n", ans);
	}


	return 0;
}