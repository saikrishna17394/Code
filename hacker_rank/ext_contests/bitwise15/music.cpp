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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int dp[1001][2001];
int n,tim,s;
int h[1001],t[1001];

int main() {
	memset(dp,0,sizeof dp);

	inp(n);
	inp(tim);
	inp(s);

	for(int i=1;i<=n;i++) {
		inp(t[i]);
		inp(h[i]);
	}

	int ans=0;

	for(int i=1;i<=n;i++) {

		if(i==1) {

			for(int j=0;j<=tim;j++) {
				if(j<t[i]) {
					if(j<s)
						dp[i][j]=-1;
					continue;
				}
				int val=t[i];
				for(int k=1;val<=j;k++) {
					dp[i][j]=max(dp[i][j],k*h[i]);
					val+=t[i]+k;
				}
			}
		}
		else {
			for(int j=0;j<=tim;j++) {
				dp[i][j]=-1;

				if(j>=s) {
					dp[i][j]=max(dp[i][j],dp[i-1][j-s]);
				}

				int val=t[i];
				for(int k=1;val<=j;k++) {
					if(dp[i-1][j-val]!=-1)
						dp[i][j]=max(dp[i][j],k*h[i]+dp[i-1][j-val]);
					val+=t[i]+k;
				}

			}

		}
		ans=max(ans,dp[i][tim]);
	}

	printf("%d\n", ans);
	return 0;
}