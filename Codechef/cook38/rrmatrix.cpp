#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <list>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int gcd(int a,int b) {
	if(b==0)
		return a;

	return gcd(b,a%b);
}

int main() {
	int t,n,m,c;

	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		if(n==1 || m==1) {
			printf("%d\n",n*m);
			continue;
		}

		n--;
		m--;
		c=n/gcd(n,m);
		// cout<<c<<endl;
		// cout<<n<<" "<<m<<endl;
		printf("%d\n",1+n/c);

	}

	return 0;
}