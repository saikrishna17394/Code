#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli fun(lli n,lli k) {
	lli q=n/k;

	lli ans=(q*(q-1))/2;
	ans=ans*k;

	ans+=q*(n%k+1);
	return ans;
}
lli odd(lli n) {
	if(n<1)
		return 0;
	n=(n+1)/2;
	return n*n;
}

lli even(lli n) {
	if(n<2)
		return 0;
	if(n&1)
		n--;
	n/=2;
	return n*(n+1);
}

lli fun1(lli n,lli k) {
	if(n/k==0)
		return 0;
	lli q=n/k;

	lli ans=odd(q-1)*(k/2);
	ans+=even(q-1)*(k+1)/2;
	lli r=n%k;

	ans+=q*(r/2+1);
	return ans;
}


int main() {
	lli t,n,k,ans;
	inp(t);
	while(t--) {
		inp(n);
		inp(k);
		ans=fun(2*n-1,k)-fun(n,k);
		// cout<<ans<<" "<<fun(n,k)<<endl;
		if(k&1) {
			printf("%lld\n",ans-fun1(2*n-2,k));
		}
		else {
			lli n1=2*n-2;
			ans-=(fun(n1,k)-n1/k)/2;
			ans-=n1/k;
			printf("%lld\n",ans);
		}
	}
	return 0;
}