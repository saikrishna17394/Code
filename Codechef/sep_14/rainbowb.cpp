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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli pow1(lli n,lli k) {
	lli ret=1;
	while(k) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli fac[1000000],afac[1000000];
int n,num;
lli ans,val;

int main() {
	fac[0]=1;
	afac[0]=1;

	for(int i=1;i<1000000;i++) {
		fac[i]=((lli)i*fac[i-1])%mod;
		afac[i]=pow1(fac[i],mod-2);
	}


	inp(n);
	ans=0;

	for(int i=1;i<=(n-12);i++) {
		num=n-i;
		if(num%2==1)
			continue;
		num/=2;
		val=(fac[num-1]*afac[5])%mod;
		val=(val*afac[num-6])%mod;
		// cout<<val<<endl;
		ans+=val;
		ans%=mod;
	}

	printf("%lld\n", ans);

	return 0;
}