#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

string s[15];
int n,m;
int dp[15][15]={0};

bool check(ii p) {
	if(p.first<0 || p.first>=n || p.second<0 || p.second>=m)
		return false;
	
	if(s[p.first][p.second]=='G')
		return true;
	return false;	
}


int main() {
	cin>>n>>m;

	for(int i=0; i<n; i++)
		cin>>s[i];

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			// cout<<s[i][j]<<" : "<<endl;
			if(s[i][j]=='B')
				continue;
			// cout<<s[i][j]<<"  "<<endl;
			int dis=0;

			vector<ii> v(4);

			ii p;
			p.first=i;
			p.second=j;

			for(int k=0; k<4; k++) {
				v[k]=p;				
			}

			// cout<<i<<" "<<j<<endl;
			while(1) {
				v[0].first--;
				v[1].first++;
				v[2].second--;
				v[3].second++;

				bool ok=true;
				for(int a=0;a<4;a++) {
					// cout<<v[a].first<<" "<<v[a].second<<endl;
					if(!check(v[a]))
						ok=false;
				}

				if(!ok)
					break;

				v[0].first--;
				v[1].first++;
				v[2].second--;
				v[3].second++;

				dis++;
			}
			// cout<<i<<" "<<j<<" : "<<dis<<endl;
			dp[i][j]=dis;
		}
	}

	int ans=0;

	for(int i=0; i<n*m; i++) {
		int a1=i/m,b1=i%m;

		if(s[a1][b1]=='B')
			continue;
		for(int j=i+1; j<n*m; j++) {
			int a2=j/m,b2=j%m;
			
			if(s[a2][b2]=='B')
				continue;

			int dis = abs(a2-a1) + abs(b2-b1);

			// cout<<dis<<" "<<dp[a1][b1]<<endl;

			for(int k=0; k<=min(dp[a1][b1],dis-1); k++) {
				int k1=min(dis-k-1,dp[a2][b2]);

				// cout<<k<<" "<<k1<<endl;
				// cout<<i<<" "<<j<<endl<<endl;
				int val=4*k+1;
				val*=(4*k1+1);

				ans=max(ans, val);

			}

		}
	}


	printf("%d\n", ans);
	return 0;
}