#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <vector>
#define lli long long int
#define lim 1000200
#define mod 1000000007
#define ii pair<int,int>

using namespace std;

lli gcd(lli a,lli b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

lli pow1(lli n,lli k) {
	lli ans=1;
	while(k) {
		if(k&1)
			ans=(ans*n)%mod;
		n=(n*n)%mod;
		k>>=1;
	}
	return ans;
}

int sum(lli i,lli j) {
	lli ans=(j+1)%mod;;
	ans=( ans*((2*i+j)%mod) )%mod;

	ans=(ans*pow1(2,mod-2))%mod;
	return ans;
}
int main() {
	lli n=1e12,q,r;

	lli ans=0,val;
	lli i=2;

	while(i<=n) {
			q=n/i;
			r=n%i;
			// cout<<i<<" "<<i+r/q<<" "<<q-1<<endl;
			val=((q-1)*sum(i,r/q))%mod;
			// cout<<ans<<endl;
			ans=(ans+val)%mod;
			i=i+(r/q+1);
	}
	cout<<ans<<endl;
	return 0;
}