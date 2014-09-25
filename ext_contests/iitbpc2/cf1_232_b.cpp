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

lli t,n,num,den;

bool check(lli a) {
	for(lli i=2;i*i<=a;i++) {
		if(a%i==0)
			return false;
	}
	return true;
}

lli gcd(lli a,lli b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	cin>>t;

	while(t--) {
		cin>>n;

		if(n==2) {
			printf("1/6\n");
			continue;
		}

		for(lli i=n;;i--) {
			if(check(i)) {
				for(lli j=i+1;;j++) {
					if(check(j)) {
						// cout<<i<<" "<<j<<" "<<n<<endl;
						num=(i-2)*j;
						num+=(n-i+1)*2;
						den=2*i*j;
						break;
					}
				}
				break;
			}
		}

		lli g=gcd(num,den);
		num/=g;
		den/=g;
		printf("%lld/%lld\n", num,den);
	}

	return 0;
}