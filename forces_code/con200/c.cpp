#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
#define lli long long int

lli gcd(lli a,lli b) {
	if(b==0)
		return a;

	return gcd(b,a%b);
}

int main() {
	lli a,b,ans;
	cin>>a;
	cin>>b;

	ans=0;

	while(gcd(a,b)!=b) {
		if(a>=b) {
			ans+=a/b;
			a=a%b;
		}
		else if(a==1) {
			ans+=b;
			a=0;
		}
		else {
			ans++;
			int val=b/a;

			b=b-val*a;
		}
	}
	ans+=a/b;
	cout<<ans<<endl;
	return 0;
}