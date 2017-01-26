#include <bits/stdc++.h>
#define ii pair<int,int>
#define lli long long int
#define lim 100001

using namespace std;

lli A[1000][1000],n;
lli dp[1000][1000];


int main() {
	cin.sync_with_stdio(false);

	while(1) {
		cin>>n;
	
		if(n==0)
			break;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				cin>>A[i][j];
	
		dp[n-1][0]=A[n-1][0];
		
		for(int i=n-2;i>=0;i--) {
			lli sum=0;
			for(int j=0;j<(n-i-1);j++) {
				sum+=A[i+j][j];
				if(j>0)
					dp[i][j]=max(dp[i+1][j]+sum,dp[i][j-1]+A[i+j][j]);
				else
					dp[i][j]=max(dp[i+1][j]+sum,A[i+j][j]);
			}
			dp[i][n-i-1]=dp[i][n-i-2]+A[n-1][n-i-1];
		}
		lli ans=0;
		
		for(int i=0;i<n;i++)
			ans=max(ans,dp[0][i]);
		cout<<ans<<endl;
	}
	return 0;
}
