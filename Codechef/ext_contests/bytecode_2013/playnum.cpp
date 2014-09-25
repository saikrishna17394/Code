#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

lli t,n,q,a,b,A[1000001],cum[1000001],tree[1000001];



int main() {

	inp(t);
	lli ans;
	while(t--) {
		inp(n);
		inp(q);
		cum[0]=0;
		for(int i=1;i<=n;i++) {
			inp(A[i]);
			//cum[i]=cum[i-1]+A[i];
			//tree[i]=cum[i]-cum[i-(i&-i)];
			//cout<<i<<" "<<tree[i]<<endl;
		}

		memset(tree,0,sizeof tree);

		

		ans=0;
		while(q--) {
			inp(a);
			inp(b);
			//ans+=B[b-a];
			//cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}

	return 0;
}