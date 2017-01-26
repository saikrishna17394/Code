#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

int n,m,k;
lli A[18];
lli dp[1<<18][18];
lli B[18][18];

int main(){ 
	// cin.sync_with_stdio(false);
	
	memset(A,0,sizeof A);
	memset(B,0,sizeof B);
	memset(dp,0,sizeof dp);

	cin>>n>>m>>k;

	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<k;i++) {
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		cin>>B[a][b];
	}

	lli ans=0;
	for(int i=1;i<(1<<n);i++) {
		int msk=i;

		int val=0;
		// cout<<i<<" : "<<endl;
		for(int j=0;j<n;j++) {
			if(msk%2==1) {
				int msk1=i;
				dp[i][j]=A[j];
				for(int l=0;l<n;l++) {
					
					if(l==j) {
						msk1/=2;
						continue;
					}
					if(msk1%2==1)
						dp[i][j]=max(dp[i][j],dp[i^(1<<j)][l]+A[j]+B[j][l]);
					msk1/=2;
				}
				val++;
				// cout<<i<<" dfsdf "<<j<<" "<<dp[i][j]<<endl;
			}
			msk/=2;
		}
		if(val==m) {
			// cout<<i<<" "<<val<<" "<<m<<endl;
			for(int j=0;j<n;j++) {
				ans=max(ans,dp[i][j]);
				// cout<<dp[i][j]<<endl;
			}
				
		}
	}

	cout<<ans<<endl;
	return 0;
}