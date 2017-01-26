#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int dp[51][51][2];

int main(){ 
	// cin.sync_with_stdio(false);
	
	int n1,n2,k1,k2;

	cin>>n1>>n2>>k1>>k2;

	for(int i=0;i<51;i++) {
		dp[0][i][0]=0;
		if(i>0) {
			dp[i][0][0]=1;
			dp[0][i][1]=1;
		}
		dp[i][0][1]=0;
	}

	// cout<<n1<<" "<<n2<<endl;
	for(int i=1;i<=n1;i++) {
		for(int j=1;j<=n2;j++) {

			int val=0;

			for(int k=1;k<=k1 && i>=k;k++) {
				if(dp[i-k][j][1]==0)
					val=1;
			}
			dp[i][j][0]=val;

			val=0;

			for(int k=1;k<=k2 && j>=k;k++) {
				if(dp[i][j-k][0]==0)
					val=1;
			}
			dp[i][j][1]=val;

			// cout<<i<<" "<<j<<" : "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
		}
	}

	if(dp[n1][n2][0]==1)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}