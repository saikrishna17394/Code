#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#include <map>
#define lli long long int
#define lim 1000200

using namespace std;
lli fac[10];
lli fun(lli n) {
	lli num=n,val=0;
	while(num) {
		val+=fac[num%10];
		num/=10;
	}
	return val;
}
int main() {
	lli n,ans=0;
	fac[0]=1;
	for(lli i=1;i<10;i++) {
		fac[i]=i*fac[i-1];
		cout<<i<<" "<<fac[i]<<endl;
	}
	// cout<<fun(148)<<endl;
	for(lli i=1;i<1000000;i++) {
		if(i==fun(i)) {
			ans+=i;
			cout<<i<<endl;
		}
	}

	cout<<ans<<endl;

	return 0;
}