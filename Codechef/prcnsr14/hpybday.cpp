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
#define lim 1001
using namespace std;

inline bool inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
	if(ch=='\n' || ch==EOF)
		return true;
	return false;
}

lli dp[14][50],t,n;

int main() {
	memset(dp,0,sizeof dp);
	dp[0][1]=1;

	for(int i=1;i<10;i++)
		dp[i][1]=1;

	for(int j=2;j<50;j++) {
		dp[0][j]=1;

		for(int i=1;i<14;i++) {

			for(int k=0;k<=9;k++) {
				if(i>=k)
					dp[i][j]+=dp[i-k][j-1];
			}
		}
	}
	// cout<<dp[1][2]<<endl;
	inp(t);

	while(t--) {
		inp(n);

		int ans=0;

		for(int j=0;j<50;j++) {
			ans+=dp[13][j];

			if(j>0)
				ans-=dp[13][j-1];
			if(ans>=n) {
				printf("%d\n", j);
				break;
			}
		}
		// printf("%d\n", ans);
	}



	return 0;
}