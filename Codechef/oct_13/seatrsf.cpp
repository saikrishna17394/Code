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
lli pow1(lli n,lli k) {
	lli ans=1;
	while(k) {
		if(k&1)
			ans=(ans*n)%mod;
		n=(n*n)%mod;
		k>>=1;
	}
	return ans;
}

int main() {
	lli t,n,m,q,k,ans;

	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(q);
		inp(k);
		if(m-1<q)
			printf("0\n");
		else {
			ans=pow1(q+1,n);
			ans-=2*pow1(q,n);
			ans+=pow1(q-1,n);

			ans%=mod;
			if(ans<0)
				ans+=mod;
			ans=(ans*(m-q))%mod;
			printf("%lld\n",ans);
		}
	}

	return 0;
}