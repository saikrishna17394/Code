#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int t,n,A[1000],k;
int dp[1024][1000];

int main() {
	cin>>t;

	while(t--) {
		cin>>n>>k;
		memset(dp,0,sizeof dp);

		for(int i=0;i<n;i++) {
			cin>>A[i];
			dp[0][i]=1;

			if(i==0) {
				dp[A[i]][i]=1;
				continue;
			}

			for(int j=0;j<1024;j++) {
				dp[j][i]|=dp[j][i-1];
				dp[j^A[i]][i]|=dp[j][i-1];
			}
			dp[A[i]][i]=1;
		}

		int ans=k;
		for(int i=0;i<1024;i++) {
			if(dp[i][n-1]) {
				// cout<<i<<endl;
				ans=max(ans,i^k);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}