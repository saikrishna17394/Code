#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

lli dp[1010][100];
lli n,k,m;

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>n>>k>>m;

	memset(dp,0,sizeof dp);

	for(int i=1;i<10;i++) {
		dp[0][i%k]++;
		// cout<<i<<" "<<dp[0][i%k]<<endl;
	}

	if(n==1) {
		cout<<dp[0][0]%m<<endl;
		return 0;
	}


	lli val=1;

	lli ans=dp[0][0],ans1;

	// cout<<"0 : "<<ans<<endl;

	for(lli i=1;i<n;i++) {
		val*=10;
		val%=k;

		for(lli j=1;j<(lli)10;j++) {
			for(lli a=1;a<k;a++) {
				dp[i][(j*val+a)%k]+=dp[i-1][a];
				dp[i][(j*val+a)%k]%=m;
			}
			dp[i][(j*val)%k]++;
			dp[i][(j*val)%k]%=m;
		}

		ans=(ans*9)%m;
		ans+=dp[i][0];
		ans%=m;

		
		cout<<i<<" : "<<ans<<endl;
		for(lli j=1;j<k;j++) {
			printf("%lld ",dp[i][j] );
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=m;
		}
		printf("\n");
	}

	cout<<ans<<endl;

	return 0;
}