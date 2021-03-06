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
#define lli unsigned long long int
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

lli solve(lli n) {
	if(n==1)
		return 0;
	if(n&1)
		return 1+solve(n/2+1);
	return solve(n/2);
}
int main() {
	lli t,n;

	inp(t);

	while(t--) {
		inp(n);
		printf("%lld\n", solve(n));
	}

	return 0;
}