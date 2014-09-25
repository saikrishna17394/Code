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
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

inline bool inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
	if(ch=='\n' || ch==EOF)
		return true;
	return false;
}

int main() {
	lli n,x,y,a1,a2,b1,b2;

	inp(n);

	a1=-inf;
	b1=-inf;

	a2=inf;
	b2=inf;

	while(n--) {
		inp(x);
		inp(y);

		a1=max(a1,x);
		a2=min(a2,x);

		b1=max(b1,y);
		b2=min(b2,y);


	}

	lli ans=(a1-a2)*(b1-b2);

	if(a1==a2 && b1==b2)
		printf("1\n");
	else if(a1==a2)
		printf("%lld\n", b1-b2);
	else if(b1==b2)
		printf("%lld\n",a1-a2);
	else
		printf("%lld\n", (a1-a2)*(b1-b2));
	return 0;
}