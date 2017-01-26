#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000001

using namespace std;

lli power(lli n,lli k) {
	lli ret=1;

	while(k>0) {
		ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

vector<int> v[10000001];
lli dp[10000001];

lli t,n,m,l,r;

int main() {
	
	for(int i=2;i<lim;i++) {
		// cout<<i<<endl;
		for(int j=2*i;j<lim;j+=i) {
			//cout<<j<<" "<<i<<endl;
			v[j].push_back(i);
		}
	}
	cin>>t;
	printf("yoo\n");

	while(t--) {
		cin>>n>>m>>l>>r;

		lli ans=0;

		dp[1]=1;

		for(lli i=2;i<m;i++) {
			dp[i]=power(i,n);
			dp[i]+=(mod-1);
			for(int j=0;j<v[i].size();j++) {
				lli num=i/v[i][j];
				dp[i]+=mod-dp[num];
			}
			dp[i]%=mod;
		}

		for(lli i=l;i<=r;i++) {
			lli val=m/i;
			ans+=dp[val];
			ans%=mod;
		}
		printf("%lld\n",ans);
	}

	return 0;
}