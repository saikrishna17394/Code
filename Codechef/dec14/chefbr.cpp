#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int t,n,A[100];

lli dp[100][100],dp1[100][100];

int main() {
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i];

	if(n==1) {
		printf("1\n");
		return 0;
	}

	memset(dp,0,sizeof dp);
	memset(dp1,0,sizeof dp);

	dp[n-1][n-1]=1;
	dp1[n-1][n-1]=1;
	
	// for(int i=0;i<n;i++)
	// 	printf("%d ",i );
	// printf(":\n");
	for(int i=0;(i+1)<n;i++) {
		dp[i][i+1]=1;
		dp[i][i]=1;
		dp1[i][i]=1;
		if(A[i]<0 && (A[i]+A[i+1])==0)
			dp[i][i+1]++;
		dp1[i][i+1]=dp[i][i+1];
		// printf("%lld ",dp1[i][i+1] );
	}
	// printf("\n");

	for(int l=2;l<n;l++) {
		for(int i=0;(i+l)<n;i++) {
			dp[i][i+l]=dp[i+1][i+l];
			dp1[i][i+l]=dp1[i+1][i+l];

			// if(i==1 && l==3) {
			// 	printf("%lld -----\n",dp[i][i+l] );
			// }
			if(A[i]<0) {
				if((A[i]+A[i+1])==0) {
					dp[i][i+l]++;
					dp1[i][i+l]+=dp1[i+2][i+l];
				}
				for(int j=i+2;j<(i+l);j++) {
					dp1[i][i+l]%=mod;
					if((A[i]+A[j])==0) {
						dp[i][i+l]+=(dp1[i+1][j-1]);
						dp1[i][i+l]+=(dp1[i+1][j-1]*dp1[j+1][i+l])%mod;
					}
				}
				if(A[i]+A[i+l]==0) {
					dp[i][i+l]+=dp1[i+1][i+l-1];
					dp1[i][i+l]+=(dp1[i+1][i+l-1]);
				}
			}
			dp[i][i+l]%=mod;
			dp1[i][i+l]%=mod;
			// printf("%lld,%lld ",dp[i][i+l],dp1[i][i+l] );
			// printf("%lld ",dp[i][i+l] );
		}
		// printf("\n");
	}

	printf("%lld\n", dp1[0][n-1]);

	return 0;
}