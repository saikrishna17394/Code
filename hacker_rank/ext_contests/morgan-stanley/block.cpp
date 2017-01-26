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
#define inf (lli)1e16

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


lli t;
int n;
lli dp[32][32],dp1[32][32];

string s[32];

int main() {
	inp(t);

	while(t--) {
		cin>>n;
		memset(dp,0,sizeof dp);
		memset(dp1,0,sizeof dp);

		for(int i=0;i<n;i++)
			cin>>s[i];

		dp[0][0]=1;

		for(int i=1;i<n;i++) {
			if(s[i][0]=='.')
				dp[i][0]=dp[i-1][0];
			if(s[0][i]=='.')
				dp[0][i]=dp[0][i-1];
		}

		for(int i=1;i<n;i++) {
			for(int j=1;j<n;j++) {
				if(s[i][j]=='#') 
					dp[i][j]=0;
				else
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}

		dp1[n-1][n-1]=1;

		for(int i=n-2;i>=0;i--) {
			if(s[i][n-1]=='.')
				dp1[i][n-1]=dp1[i+1][n-1];
			if(s[n-1][i]=='.')
				dp1[n-1][i]=dp1[n-1][i+1];
		}

		for(int i=n-2;i>=0;i--) {
			for(int j=n-2;j>=0;j--) {
				if(s[i][j]=='#')
					dp1[i][j]=0;
				else
					dp1[i][j]=dp1[i+1][j]+dp1[i][j+1];
			}
		}

		lli ans=0;


		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(s[i][j]=='#')
					continue;
				if(i==0 && j==0)
					continue;
				if(i==(n-1) && j==(n-1))
					continue;

				lli val=dp[i][j]*dp1[i][j];

				// if((i+1)<n)
				// 	val+=dp[i][j]*dp1[i+1][j];
				// if((j+1)<n)
				// 	val+=dp[i][j]*dp1[i][j+1];
				ans=max(ans,val);
				// cout<<i<<" "<<j<<" "<<val<<endl;
			}
		}


		cout<<dp[n-1][n-1]-ans<<endl;
	}


	return 0;
}