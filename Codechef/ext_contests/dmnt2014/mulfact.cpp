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
#define ii pair<long long int,long long int>

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
lli dp[1000000],dp1[1000000];

lli n,m;
lli mod=329885391853;

lli mult(lli a,lli b) {
	lli num=1;
	lli ret=0;

	while(b) {
		if(b&1) {
			ret+=
		}
		num=(num*2)%mod;
	}
}
int main() {
	dp[0]=1;
	dp1[0]=1;

	for(lli i=1;i<1000000;i++) {
		dp[i]=(dp[i-1]*i)%mod;
		dp1[i]=mult(dp[i],dp1[i-1]);
	}

	inp(n);

	while(n--) {
		inp(m);
		if(m>=1000000)
			printf("0\n");
		else
			printf("%lld\n", dp1[m]);
	}

	return 0;
}