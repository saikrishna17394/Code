#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<long long int,long long int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int A[1010][1010];
int dp[1010][1010][2];

int r,c;

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>r>>c;


	int ans=1;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&A[i][j]);
	
	for(int i=0;i<r;i++) {
		for(int j=c-1;j>=0;j--) {
			// scanf("%d",&A[i][j]);

			dp[i][j][0]=1;
			dp[i][j][1]=1;

			if((i>0) && A[i-1][j]==A[i][j])
				dp[i][j][0]=dp[i-1][j][0]+1;

			if(j<(c-1) && A[i][j+1]==A[i][j])
				dp[i][j][1]=dp[i][j+1][1]+1;
			// cout<<A[i][j]<<" ";
			// cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
			ans=max(ans,dp[i][j][0]+dp[i][j][1]-1);
		}
	}

	printf("%d\n", ans);

	return 0;
}