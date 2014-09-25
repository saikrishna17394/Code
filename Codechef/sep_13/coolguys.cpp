#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

lli gcd(lli a,lli b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main() {
	lli t,n,q,r,den,num,i,g;
	inp(t);

	while(t--) {
		inp(n);
		den=n*n;
		num=n;

		i=2;
		while(i<=n) {
			q=n/i;
			r=n%i;
			num+=q*(r/q+1);			
			i=i+(r/q+1);
		}
		g=gcd(num,den);
		num/=g;
		den/=g;
		printf("%lld/%lld\n",num,den);
	}
	return 0;
}