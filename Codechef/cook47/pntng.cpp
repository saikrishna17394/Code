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

lli n,m,h;
ii A[100010];

int main() {
	inp(n);
	inp(m);
	inp(h);

	for(int i=0;i<h;i++) {
		inp(A[i].second); 
		inp(A[i].first);
	}

	sort(A,A+h);

	lli ans=0,rem=0,area=n*m,idx=0,val;

	while(rem<area) {
		// printf("%lld %lld\n", rem,area);
		if(idx>=h)
			break;
		val=min(area-rem,A[idx].second);
		rem+=val;
		ans+=val*A[idx].first;

		idx++;
	}

	if(rem<area)
		printf("Impossible\n");
	else
		printf("%lld\n", ans);
	return 0;
}