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
#define lim 100010
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli t,s,A[4],num[101],dp[101][101];

lli pow1(lli n,int k) {
	lli ret=1;
	while(k) {
		if(k&1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k>>=1;
	}
	return ret;
}
lli solve(lli idx,lli sum) {
	// cout<<idx<<" "<<sum<<endl;
	if(sum==0)
		return 1;
	if(idx>sum)
		return 0;

	lli &ret=dp[idx][sum];
	if(ret!=-1)
		return ret;

	ret=solve(idx+1,sum);
	lli val=1;

	if(num[idx]>0) {
		val=1;
		for(lli i=1;i*idx<=sum;i++) {
			val=(val*(num[idx]+i-1))%mod;
			val=(val*pow1(i,mod-2))%mod;
			
			ret=(ret+val*solve(idx+1,sum-i*idx))%mod;
			ret%=mod;

		}
	}
	return ret;
}

int main() {
	inp(t);
	while(t--) {
		for(int i=0;i<4;i++)
			inp(A[i]);
		inp(s);
		for(lli i=1;i<=s;i++) {
			num[i]=A[0];
			num[i]+=A[1]*i;
			num[i]+=A[2]*i*i;
			num[i]+=A[3]*i*i*i;
			// cout<<i<<" "<<num[i]<<endl;
		}
	
		memset(dp,-1,sizeof dp);
		// cout<<" ans ";
		printf("%lld\n", solve(1,s));
	
	}
	return 0;
}