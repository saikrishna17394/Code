#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int dp[lim][301];
int n,m,s,e;
int A[lim],B[lim];
vector<int> v[lim];

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n>>m>>s>>e;

	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<m;i++) {
		cin>>B[i];
		v[B[i]].push_back(i);
	}

	int ans=0;

	for(int i=0;i<n;i++) {
		if(i>0)
			dp[i][1]=dp[i-1][1];
		else
			dp[i][1]=inf;

		if(v[A[i]].size()>0) {
			dp[i][1]=min(dp[i][1],v[A[i]][0]);
		}

		if((dp[i][1]+1+i+1+e)<=s)
			ans=1;
	}

	for(int j=2;j<=s/e;j++) {
		dp[0][j]=inf;

		for(int i=1;i<n;i++) {
			dp[i][j]=dp[i-1][j];

			if(!v[A[i]].empty()) {
				int l=0,r=v[A[i]].size()-1;

				while(l<r) {
					int m=(l+r)/2;

					if(dp[i-1][j-1]<v[A[i]][m])
						r=m;
					else
						l=m+1;
				}

				if(dp[i-1][j-1]<v[A[i]][l])
					dp[i][j]=min(dp[i][j],v[A[i]][l]);
			}
			if((dp[i][j]+1+i+1+e*j)<=s)
				ans=j;
		}
	}

	cout<<ans<<endl;

	return 0;
}