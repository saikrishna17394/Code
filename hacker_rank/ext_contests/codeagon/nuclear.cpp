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

int dp[100][100][101],n,m,z;

string s1,s2,s3;

int main() {
	cin>>s1>>s2>>s3;

	n=s1.length();
	m=s2.length();
	z=s3.length();

	memset(dp,0,sizeof dp);

	if(s1[0]==s2[0])
		dp[0][0][0]=1;

	for(int i=1;i<n;i++) {
		if(s1[i]==s2[0])
			dp[i][0][0]=1;
		else
			dp[i][0][0]=dp[i-1][0][0];
	}

	for(int j=1;j<m;j++) {
		if(s1[0]==s2[j])
			dp[0][j][0]=1;
		else
			dp[0][j][0]=dp[0][j-1][0];
	}

	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			if(s1[i]==s2[j])
				dp[i][j][0]=dp[i-1][j-1][0]+1;
			else
				dp[i][j][0]=max(dp[i][j-1][0],dp[i-1][j][0]);
		}
	}

	for(int k=1;k<=z;k++) {
		dp[0][0][k]=dp[0][0][0];

		if(k==1 && dp[0][0][k]==1 && s1[0]==s3[k-1])
			dp[0][0][k]=0;

		for(int i=1;i<n;i++) {
			dp[i][0][k]=dp[i][0][0];

			if(k==1 && dp[i][0][k]==1 && s2[0]==s3[k-1])
				dp[i][0][k]=0;

			// if(s1[i]==s2[0] && s3[k-1]==s2[0])
			// 	dp[i][0][k]=0;
		}

		for(int j=1;j<m;j++) {
			dp[0][j][k]=dp[0][j][0];

			if(k==1 && dp[0][j][k]==1 && s1[0]==s3[k-1])
				dp[0][j][k]=0;
			// if(s1[0]==s2[j] && s3[k-1]==s1[0])
			// 	dp[0][j][k]=0;
		}

		for(int i=1;i<n;i++) {
			for(int j=1;j<m;j++) {
				if(s1[i]==s2[j] && s1[i]==s3[k-1]) {
					dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);

					if(k>1)
						dp[i][j][k]=max(dp[i-1][j-1][k-1]+1,dp[i][j][k]);
				}
				else if(s1[i]==s2[j] && s2[j]!=s3[k-1]) {
					dp[i][j][k]=dp[i-1][j-1][k]+1;
				}
				else {
					dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);
				}
			}
		}
	}

	cout<<dp[n-1][m-1][z]<<endl;

	return 0;
}