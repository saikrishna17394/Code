#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

lli pov(lli n,lli k) {
	lli ret=1;
	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli n,k,m;

int main() {
	cin>>n>>k>>m;

	lli ans;

	n--;
	if(k==1)
		ans=1;
	else if(k==2) {
		ans=(2*n+1)%mod;
	}
	else if(k==3) {
		ans=(2*n)%mod;
		ans=(ans*(n+1))%mod;
		ans=(ans+1)%mod;
	}
	else if(k==4) {
		ans=(n*(n+1))%mod;
		ans=(ans*((2*n+1)%mod))%mod;
		ans=(ans*2)%mod;
		ans=(ans*pov(3,mod-2))%mod;

		ans+=(2*n+1);

		ans%=mod;
	}
	else {
		lli val=(n*(n+1))%mod;

		ans=(2*((val*val)%mod))%mod;
		ans+=(2*val);

		ans%=mod;

		ans=(ans*pov(3,mod-2))%mod;

		ans+=(2*val+1);

		ans%=mod;

	}
	ans=(ans*m)%mod;
	cout<<ans<<endl;
	return 0;
}