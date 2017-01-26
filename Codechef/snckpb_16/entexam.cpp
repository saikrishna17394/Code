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

lli t,n,k,e,m;
lli A[10000];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		inp(e);
		inp(m);

		for(lli i=0;i<(n-1);i++) {
			A[i] = 0;
			lli val;
			// cout<<i<<" : ";
			for(lli j=0;j<e;j++) {
				inp(val);
				// cout<<val<<" ";
				A[i]+=val;
			}
			// printf("\n");
		}

		A[n-1] = 0;
		lli val;
		for(lli i=0;i<(e-1);i++) {
			inp(val);
			A[n-1]+=val;
		}

		sort(A,A+n-1);


		// for(int i=0;i<n;i++)
		// 	cout<<A[i]<<" \n";

		lli ans = A[n-k-1] + 1 - A[n-1];

		ans = max(ans,(lli)0);

		if(ans <= m) {
			printf("%lld\n", ans);
		}
		else
			printf("Impossible\n");;
	}
	return 0;
}