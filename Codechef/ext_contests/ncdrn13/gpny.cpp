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

long long int t,n,a,b,prev,ans,sm,big,c,A[2],B[2];

int main() {

	inp(t);

	while(t--) {
		inp(n);
		inp(A[0]);
		inp(B[0]);

		sm=A[0];
		ans=0;
		c=A[0];

		for(int j=1,i=1;j<=n;j++) {
			inp(A[i]);
			inp(B[i]);

			prev=c;

			if(A[i]<A[i-1])
				c+=A[i-1]-A[i];
			if(B[i]<B[i-1])
				c+=B[i-1]-B[i];
			
			if(A[i]>A[i-1])
				c-=(A[i]-A[i-1]);
			if(B[i]>B[i-1])
				c-=(B[i]-B[i-1]);
			
			if(c<0)
				c=(A[i]+B[i]+2*prev-A[i-1]-B[i-1]);

			if(c==0) {
				sm=(lli)1e18;
			}
			else {
				ans=max(ans,c-sm);
				sm=min(sm,c);
			}
			A[0]=A[1];
			B[0]=B[1];
		}
		printf("%lld\n", ans);
	}

	return 0;
}