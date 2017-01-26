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
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n1,n2,sum,n,a,d;

int main() {
	inp(t);

	while(t--) {
		inp(n1);
		inp(n2);
		inp(sum);

		n=(2*sum)/(n1+n2);
		d=(n2-n1)/(n-5);
		a=n1-3*d;

		printf("%lld\n", n);

		for(lli i=1;i<=n;i++)
			printf("%lld ", a+i*d);
		printf("\n");
	}

	return 0;
}