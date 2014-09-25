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

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

lli gcd(lli a,lli b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	lli t,n,m,num,den;

	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		if(n%2==0 || m%2==0) {
			printf("1/2\n");
		}
		else {
			num=n*(m-1);
			num/=2;
			num+=n/2;
			
			den=n*m;

			lli g=gcd(num,den);
			printf("%lld/%lld\n", num/g,den/g);	
		}
	}



	return 0;
}