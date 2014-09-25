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
#define inf 999999999
#define lim 10000000

using namespace std;

lli n,s;
lli A[20];

lli power(lli n,lli k) {
	lli ret=1;

	while(k) {
		// cout<<"yo\n";
		if(k&1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

map<lli,lli> m;

int main() {
	cin>>n>>s;

	for(int i=0;i<n;i++)
		cin>>A[i];

	// cout<<"bro\n";
	
	int val=1<<n;

	for(int j=0;j<val;j++) {
		// cout<<"what\n";
		int mask=j;

		lli ex=0;
		lli coef=1;

		for(int i=0;i<n;i++) {
			if(mask&1) {
				ex+=A[i]+1;
				coef*=-1;
			}

			mask/=2;
		}

		if(ex<=s)
			m[ex]+=coef;
	}
	// cout<<"bro\n";

	lli ans=0,inv=1;

	for(lli i=1;i<=(n-1);i++)
		inv=(inv*i)%mod;
	inv=power(inv,mod-2);

	for(map<lli,lli>::iterator it=m.begin();it!=m.end();it++) {
		lli num=(inv*it->second)%mod;

		lli i=s-it->first+1;

		for(int j=1;j<=(n-1);j++) {
			// cout<<" "<<num<<endl;
			num=(num*(i%mod))%mod;
			i++;
		}

		ans+=num;

		// cout<<it->first<<" "<<it->second<<" "<<num<<" "<<ans<<endl;
	}

	ans%=mod;
	if(ans<0)
		ans+=mod;
	cout<<ans<<endl;

	return 0;
}