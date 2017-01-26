#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int t,n,A[110];
int dp[110][110];

int main(){ 
	cin>>t;

	while(t--) {
		cin>>n;

		for(int i=0;i<n;i++) {
			cin>>A[i];
		}
		dp[0][n-1]=0;

		for(int j=n-2;j>=0;j--) {
			for(int i=0;(i+j)<n;i++) {
				dp[i][i+j]=inf;
				// cout<<i<<" "<<i+j<<" : \n";
				if(i>0) {
					int val=0,val1=0;

					for(int k=0;k<n;k++) {
						if(k>=(i-1) && k<=(i+j))
							continue;
						if(A[k]>A[i-1])
							val++;
						if(A[k]<A[i-1])
							val1++;
					}

					dp[i][i+j]=min(val,val1)+dp[i-1][i+j];
					// cout<<val<<" "<<val1<<" "<<dp[i-1][i+j]<<endl;;
				}

				if((i+j+1)<n) {
					int val=0,val1=0;

					for(int k=0;k<n;k++) {
						if(k>=i && k<=(i+j+1))
							continue;
						if(A[k]>A[i+j+1])
							val++;
						if(A[k]<A[i+j+1])
							val1++;
					}

					int ret=min(val,val1)+dp[i][i+j+1];
					dp[i][i+j]=min(dp[i][i+j],ret);
					// cout<<val<<" "<<val1<<" "<<dp[i][i+j+1]<<endl;
				}
				// cout<<dp[i][i+j]<<endl;
			}
		}

		int ans=inf;

		for(int i=0;i<n;i++) {
			int val=0,val1=0;

			for(int k=0;k<n;k++) {
				if(k==i)
					continue;
				if(A[k]>A[i])
					val++;
				if(A[k]<A[i])
					val1++;
			}
			ans=min(ans,min(val,val1)+dp[i][i]);
		}

		printf("%d\n", ans);

	}	

	return 0;
}