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
	lli t,n,A[10],ans,a,b,a1,b1;
	inp(t);
	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			inp(A[i]);

		a=b=A[0];

		for(int i=1;i<n;i++) {
			// cout<<a<<" "<<b<<endl;
			if(A[i]>0) {
				if(a<0)
					a+=A[i];
				else
					a=max(a+A[i],a*A[i]);
				if(b>0)
					b-=A[i];
				else
					b=min(b-A[i],b*A[i]);
			}
			if(A[i]<0) {
				a1=a;b1=b;
				if(a<0)
					a=max(b*A[i],a-A[i]);
				else
					a=max(a-A[i],b*A[i]);

				b=min(a1*A[i],b1+A[i]);
			}
			if(A[i]==0) {
				if(a<0)
					a=0;
				if(b>0)
					b=0;
			}
		}
		// cout<<a<<" "<<b<<endl;
		printf("%lld\n", b);
	}
	return 0;
}