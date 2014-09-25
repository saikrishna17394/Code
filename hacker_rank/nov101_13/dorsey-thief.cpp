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

lli x,n,v[lim],a[lim];
lli cost[5001],cnt[5001]={0};
vector<lli> cost1[5001];
lli dp[5001][5001];

int main() {
	inp(n);
	inp(x);

	memset(cost,0,sizeof cost);
	memset(dp,0,sizeof dp);

	for(int i=0;i<n;i++) {
		inp(v[i]);
		inp(a[i]);
		if(a[i]<=x) {
			cost1[a[i]].push_back(v[i]);
			cnt[a[i]]++;
		}
	}

	for(int i=1;i<=x;i++) {
		sort(cost1[i].begin(),cost1[i].end());
	}

	for(int i=1;i<=x;i++) {
		for(int j=0;j<=x;j++)
			dp[i][j]=dp[i-1][j];
		int sum=0;
		lli val=0;
		for(int k=cost1[i].size()-1;k>=0;k--) {
			sum+=i;
			val+=cost1[i][k];
			if(sum>x)
				break;
			dp[i][sum]=max(dp[i][sum],val);

			for(int j=sum+1;j<=x;j++)
				if(dp[i-1][j-sum])
					dp[i][j]=max(dp[i][j],dp[i-1][j-sum]+val);
		}
	}

	if(dp[x][x])
		printf("%lld\n", dp[x][x]);
	else
		printf("Got caught!\n");
	return 0;
}