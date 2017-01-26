#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<long long int,long long int>
#define mod 1000000007
#define inf 999999999
#define lim 1010

using namespace std;



int t,n,x;
int dp[lim][lim];
int A[lim];


int main(){ 
	// cin.sync_with_stdio(false);

	cin>>t;

	for(int j=0;j<lim;j++)
		dp[0][j]=0;

	while(t--) {
		cin>>n>>x;

		for(int i=1;i<=n;i++) {
			scanf("%d",&A[i]);
			A[i]-=x;
		}

		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i<j) {
					dp[i][j]=dp[i][j-1];
					// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
					continue;
				}

				if(j==1) {
					dp[i][j]=i*A[j];
				}
				else {
					dp[i][j]=max(dp[i][j-1],A[j]+dp[i-j][j]);					
				}

				// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}


		cout<<dp[n][n]<<endl;

	}



	// printf("%d\n", ans);

	return 0;
}