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
#define lim 100001
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

inline lli pow1(lli n,lli k) {
	lli ans=1,num=n;
	// cout<<n<<"  sa "<<k<<endl;
	while(k) {
		// cout<<n<<" "<<k<<endl;
		if(k&1)
			ans=(ans*num)%mod;
		num=(num*num)%mod;
		k>>=1;
	}
	return ans;
}

lli A[lim],t,n,k,ans,sign,num,den,val,val1,inv[lim];

int main() {
	A[0]=1;

	for(lli i=1;i<lim;i++) {
		A[i]=(i*A[i-1])%mod;
		inv[i]=pow1(i,mod-2);
	}

	inp(t);

	while(t--) {
		inp(n);
		inp(k);

		ans=A[n];
		sign=-1;
		val=1;
		num=k;
		den=1;
		for(lli i=1;i<=k;i++) {
			// cout<<i<<" "<<ans<<endl;
			val=(val*num)%mod;
			val=(val*inv[den])%mod;

			val1=(val*A[n-i])%mod;
			val1*=sign;

			ans=(ans+val1)%mod;
			// ans=(ans+mod)%mod;

			num--;
			den++;
			sign*=-1;
			// cout<<i<<" "<<ans<<endl;
		}
		if(ans<0)
			ans+=mod;
		printf("%lld\n", ans);
	}
	return 0;
}