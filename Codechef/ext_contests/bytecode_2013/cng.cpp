#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	lli t,a,b,ans;
	inp(t);

	while(t--) {
		inp(a);
		inp(b);
		if(b<a)
			swap(a,b);
		ans=(b)*(a-2)+(b-a);

		printf("%lld\n", ans);

	}
	return 0;
}
