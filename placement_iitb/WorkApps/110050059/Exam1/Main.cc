#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
long long int A[500][501];
long long int dp[500][501];

int main() {

	cin>>n>>m;

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%lld",&A[i][j]);
		}
	}

	for(int i=0;i<n;i++) {
		A[i][m]=0;
	}

	for(int i=0;i<n;i++) {
		dp[i][0]=A[i][0];
	}

	for(int j=1;j<=m;j++) {
		for(int i=0;i<n;i++) {

			dp[i][j]=-1;			
			if(A[i][j]==-1)
				continue;
			
			long long int val=A[i][j];

			for(int k=0;k<n;k++) {
				int ind=(i+k)%n;

				if(A[ind][j-1] == -1)
					break;


				if(k>0 && ind<i) {
					if(dp[ind][j-1]==-1)
						continue;
					dp[i][j]=max(dp[i][j],val);
					break;
				}

				if(dp[ind][j-1] == -1) {
					val+=A[ind][j-1];
					continue;
				}

				dp[i][j]=max(dp[i][j],val+dp[ind][j-1]);
				
				val+=A[ind][j-1];
			}

			val=A[i][j];

			for(int k=n;k>0;k--) {
				int ind=(i+k)%n;

				if(A[ind][j-1] == -1)
					break;
				if(dp[ind][j-1] == -1)
					break;

				if(k<n && ind>i) {
					if(dp[ind][j-1]==-1)
						continue;
					dp[i][j]=max(dp[i][j],val);
					break;
				}

				if(dp[ind][j-1] == -1) {
					val+=A[ind][j-1];
					continue;
				}

				dp[i][j]=max(dp[i][j],val+dp[ind][j-1]);

				val+=A[ind][j-1];
			}

			// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}

	long long int ans=-1;

	for(int i=0;i<n;i++)
		ans=max(ans,dp[i][m]);

	cout<<ans<<endl;

	return 0;
}