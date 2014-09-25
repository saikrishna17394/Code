#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 1999999999
#define lim 10000000

using namespace std;

lli fac[200001],afac[200001];

lli pow1(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli ncr(int n,int k) {
	lli ret=(fac[n]*afac[k])%mod;
	ret=(ret*afac[n-k])%mod;
	// cout<<fac[5]<<" "<<afac[1]<<" "<<" "<<afac[4]<<endl;
	return ret;
}

int cur=0;
lli dp[100001];
int tim[100001];

vector<int> divs[100001];


lli solve(int n,int f) {
	if(n>1 && f==1)
		return 0;
	if(tim[n]==cur)
		return dp[n];
	tim[n]=cur;
	lli& ret=dp[n];

	ret=ncr(n-1,f-1);
	// cout<<n<<" "<<f<<"/ "<<ret<<endl;

	for(int i=0;i<divs[n].size();i++) {
		if(divs[n][i]==n)
			break;
		if(divs[n][i]>=f) {
			ret-=solve(divs[n][i],f);
			ret%=mod;
			if(ret<0)
				ret+=mod;
		}
	}
	return ret;
}

int main() {

	for(int i=1;i<100001;i++) {
		for(int j=i;j<100001;j+=i)
			divs[j].push_back(i);
	}

	fac[0]=1;
	afac[0]=1;

	// cout<<"man\n";
	for(int i=1;i<200001;i++) {
		// printf("ok  %d\n", i);
		fac[i]=((lli)i*fac[i-1])%mod;
		afac[i]=pow1(fac[i],mod-2);
		// printf("what\n" );
	}

	int q,n,f;

	cin>>q;
	memset(tim,-1,sizeof tim);

	// printf("%lld\n", ncr(0,0));
	while(q--) {
		scanf("%d %d",&n,&f);
	
		lli ans=solve(n,f);
		// cout<<ans<<" "<<n-1<<" "<<f-1<<endl;

		printf("%lld\n", ans);
		cur++;
	}

	return 0;
}