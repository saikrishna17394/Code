#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int t;
int w,h,m;

int dp[1<<7][100];

int main(){ 
	cin>>t;

	while(t--) {
		cin>>w>>h>>m;

		memset(dp,0,sizeof dp);

		int n=1<<w;

		for(int i=0;i<n;i++)
			dp[i][0]=0;

		dp[1][0]=(n/2)%m;

		for(int k=1;k<h;k++) {

			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {

					int val=0;

					int msk=i,msk1=j;
					for(int a=0;a<w;a++) {
						if( (msk1&(1<<a))==0) {
							bool ok=false;

							if( (msk&(1<<a))!=0)
								ok=true;
							if(a>0 && (msk&(1<<(a-1)))!=0)
								ok=true;
							if( a<(w-1) && (msk&(1<<(a+1)))!=0)
								ok=true;
							if(ok)
								val|=(1<<a);
						}
					}

					if(val>0) {
						dp[val][k]+=dp[i][k-1];
						dp[val][k]%=m;
					}
				}
			}
		}

		int ans=0;

		for(int i=1;i<n;i++) {
			ans=(ans+dp[i][h-1])%m;
			for(int j=0;j<h;j++)
				cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
		}

		printf("%d\n", ans);
	}

	return 0;
}