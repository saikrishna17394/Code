#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define lli long long int
#define mod 1000000009
using namespace std;

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

lli pow(lli a,lli n) {
	lli res=1;
	while(n!=0) {
		if(n&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		n=n>>1;
	}
	return res;
}
int main() {
	lli n,m,k,ans,val,num;
	cin>>n>>m>>k;


	val=(n/k)*(k-1);
	val+=n%k;


	if(m<=val)
		cout<<m%mod<<endl;
	else {
		num=m-val;
		ans=m-num*k;

		//cout<<num<<" "<<ans<<endl;

		val=pow(2,num+1)-2;
		val%=mod;
		while(val<0)
			val+=mod;
		//cout<<val<<" "<<ans<<endl;
		val=(val*k)%mod;
		//cout<<val<<" "<<ans<<endl;
		ans=(ans+val)%mod;;

		cout<<ans<<endl;

	}

	return 0;
}