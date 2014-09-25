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
	lli t,n,A[100000],suff[100000],ans,small;
	inp(t);

	while(t--) {
		inp(n);
		ans=0;
		for(int i=0;i<n;i++) {
			inp(A[i]);
			ans+=A[i];
		}
		suff[0]=A[0];
		small=A[0];

		for(int i=1;i<n;i++) {
			suff[i]=min(A[i],A[i]+suff[i-1]);
			small=min(small,suff[i]);
		}

		if(small>0)
			small=0;
		printf("%lld\n", ans-2*small);
	}
	return 0;
}