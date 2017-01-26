#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
#define mod 1000000007
#define inf 999999999
#define lim 2010
using namespace std;


int dp[2010][2010];
int dp1[lim][lim];

int main() {
	freopen("winning_at_sports.txt", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,n;


	for(int i=1;i<lim;i++)
		dp[i][0]=1;


	for(int i=1;i<lim;i++) {
		for(int j=1;j<i;j++) {
			if((j+1)==i)
				dp[i][j]=dp[i][j-1];
			else
				dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
		}
	}

	for(int i=0;i<lim;i++)
		dp1[i][0]=1;

	for(int i=1;i<lim;i++) {
		for(int j=1;j<=i;j++) {
			if(i==j)
				dp1[i][j]=dp1[i][j-1];
			else
				dp1[i][j]=(dp1[i-1][j]+dp1[i][j-1])%mod;
		}
	}
	cin>>t;

	for(int a=1;a<=t;a++) {

		int x,y;
		scanf("%d-%d",&x,&y);

		printf("Case #%d: ",a);
		
		printf("%d %d\n", dp[x][y],dp1[y][y]);
	}


	return 0;
}