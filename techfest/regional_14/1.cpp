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
int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main() {

	int n=1034568,ans=0;

	for(int i=1;i<=n;i++) {
		if(gcd(n,i)%2==0)
			ans++;
	}
	cout<<ans<<" "<<2*ans<<endl;
	return 0;
}