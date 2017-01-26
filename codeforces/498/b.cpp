#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int n,T;
int t[5000],P[5000];
double p[5000];

double dp[2][5001];

int main(){
	cin>>n>>T;

	for(int i=0;i<n;i++) {
		cin>>P[i]>>t[i];
		p[i]=(double)P[i]/100.0;
	}

	dp[(n-1)%2][0]=0;
	double val=1.0;

	for(int j=1;j<=T;j++) {
		int i=(n-1)%2;
		dp[i][j]=dp[i][j-1];

		if(j>t[n-1])
			;
		else if(j==t[n-1])
			dp[i][j]+=val;
		else
			dp[i][j]+=val*p[n-1];

		val*=(1.0-p[n-1]);
		cout<<n-1<<" "<<j<<" : "<<dp[i][j]<<endl;
	}
	

	for(int a=n-2;a>=0;a--) {
		int i=a%2;
		dp[i][0]=0;

		val=1.0;

		for(int j=1;j<=T;j++) {
			dp[i][j]=dp[i][j-1];

			if(j>t[a])
				;
			else if(j==t[a])
				dp[i][j]+=val*(1.0+dp[i^1][T-j]);
			else {
				dp[i][j]+=(val*p[a])*(1.0+dp[i^1][T-j]);
				val*=(1.0-p[a]);
			}
			cout<<a<<" "<<j<<" : "<<dp[i][j]<<endl;
		}

	}

	printf("%.6f\n", dp[0][T]);
	return 0;
}