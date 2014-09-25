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

#define mod 1000000
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

lli t,n,a,b,c,d,A[3000000],ans;
lli B[1000000];

int main() {
	inp(t);

	while(t--) {
		memset(B,0,sizeof B);
		
		inp(n);

		inp(a);
		inp(b);
		inp(c);
		inp(d);

		A[0]=d;
		ans=0;
		B[A[0]]++;
		
		lli sign=1;

		// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		for(int i=1;i<n;i++) {
			A[i]=A[i-1]*(a*A[i-1]+b);
			A[i]+=c;
			A[i]%=mod;
			// cout<<i<<" kri "<<A[i]<<endl;
			B[A[i]]++;
		}

		for(lli i=0;i<mod;i++) {
			if(B[i]&1) {
				// cout<<i<<" yo "<<B[i]<<endl;
				ans+=sign*i;
				sign*=-1;
			}
		}
		printf("%lld\n", abs(ans));

	}

	return 0;
}