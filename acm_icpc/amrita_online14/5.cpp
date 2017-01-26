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
#define ii pair<long long int,long long int>

#define mod 1000000009
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

// n^k % 10^9+7
lli power(lli n,lli k) {
	lli ret=1;

	k%=(mod-1);
	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli value(lli d,lli len) {
	lli ret=power(10,len);
	ret--;
	ret=(ret*power(9,mod-2))%mod;
	ret=(ret*d)%mod;
}

lli help(lli d,lli len) {
	if(len==1)
		return (d*(d+1))/2;
	if(d==0)
		return 0;


	lli val=value(d,len/2);
	lli h=help(d,len/2);

	lli ret=(d*((len+1)/2))%mod;
	ret=(ret*val1)%mod;
	ret+=h;
	ret%=mod;


}

int main() {
	inp(t);

	while(t--) {
		inp(m);

		for(int i=0;i<m;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}
		B[m-1]=help(A[m-1].second,A[m-1].first);
		lli len=A[m-1].first;		
		C[m-1]=len;
		for(int i=m-2;i>=0;i--) {
			B[i]=(help(A[i].second,A[i].first)*pow1((lli)10,len))%mod;
			B[i]+=B[i+1];
			B[i]%=mod;
			len+=A[i].first;
			C[i]=len;
		}

		printf("%lld\n", solve(0));

	}

	return 0;
}