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

#define mod 1008
#define inf 999999999
#define lim 1000000
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n,m,q,x;
lli A[100];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(q);
		A[0]=1%m;

		for(lli i=1;i<=n;i++) {
			A[i]=A[i-1];
			for(lli j=0;j<(n-i+1);j++)
				A[i]=(A[i]*(n-i+1));
			for(lli j=0;j<i;j++)
				A[i]/=i;
			// cout<<i<<" "<<A[i]<<endl;
			// A[i]%=m;
		}

		while(q--) {
			inp(x);
			printf("%lld\n", A[x]%m);
		}
	}

	return 0;
}