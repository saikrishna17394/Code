#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;
int t,n;
int A[2004][2004];
int dp[2004][2004]={0};

int main() {
	cin>>t;

	while(t--) {
		cin>>n;

		vector<ii> v;

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cin>>A[i][j];
				if(i==j)
					continue;
				if(A[i][j]==0) {
					dp[i][j]=inf;
					v.push_back(ii(i,j));
				}
				else
					dp[i][j]=1;
			}
		}


		for(int k=0;k<n;k++) {
			vector<ii> v1;

			for(int i=0;i<v.size();i++) {
				int a=v[i].first,b=v[i].second;
				dp[a][b]=min(dp[a][b],dp[a][k]+dp[k][b]);

				if(dp[a][b]==inf)
					v1.push_back(v[i]);
			}

			v=v1;
		}

		ii ans=ii(inf,-1);
		for(int i=0;i<n;i++) {
			int val=0;
			for(int j=0;j<n;j++) {
				val=max(val,dp[i][j]);
			}

			if(ans.first>val) {
				ans.first=val;
				ans.second=i;
			}
		}

		if(ans.second==-1) {
			printf("-1\n");
		}
		else {
			cout<<ans.first<<" "<<ans.second+1<<endl;
		}
	}

	return 0;
}