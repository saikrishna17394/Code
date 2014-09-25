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
#define ii pair<long long int,long long int>

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

int main() {
	lli t,n,ans;
	inp(t);

	while(t--) {
		inp(n);

		ans=2*n*(n-1)*(n-1);
		ans+=n*(n-1)*(n-2);
		ans+=2*n*(n-1)*(n-2)*(n-2);

		if(n<2)
			printf("0\n");
		else if(n==2)
			printf("4\n");
		else
			printf("%lld\n", ans);
	}


	return 0;
}