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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int t,n,s[2001],f[2001],dp[2001],ans;

	inp(t);

	while(t--) {
		inp(n);

		for(int i=1;i<=n;i++)
			inp(s[i]);
		for(int i=1;i<=n;i++)
			inp(f[i]);
		dp[1]=min(f[1],s[1]);
		ans=dp[1];

		for(int i=2;i<=n;i++) {
			dp[i]=min(f[i],s[i]);

			for(int j=1;j<i;j++) {
				dp[i]=max(dp[i],dp[j]+min(f[i-j],s[i]));
			}
			ans=max(ans,dp[i]);
		}

		printf("%d\n", ans);
	}

	return 0;
}