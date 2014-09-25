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
#include <ctime>

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

lli f(lli x,lli y) {
	if(x==0 && y==0)
		return 0;
	if(x%3==0) {
		if(y&1)
			return 1+f(x/3,y/2);
		return f(x/3,y/2);
	}
	if(x%3==1) {
		if(y&1)
			return 2+f(x/3,y/2);
		return 1+f(x/3,y/2);
	}
	if(y&1)
		return 1+f(x/3,y/2);
	return f(x/3,y/2);
}

int main() {
	lli t,x,y;

	inp(t);

	while(t--) {
		inp(x);
		inp(y);
		printf("%lld\n", f(x,y));
	}

	return 0;
}