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

#define mod 1000000000

#define inf (lli)1e16

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli power(lli n,lli k) {
	lli ret=1;
	n%=mod;

	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli t,n,dp[20];

lli solve(lli i) {
	if(i<=(lli)10)
		return dp[i];

	lli ret=power((lli)2,(i+3)/4);

	ret=(ret*solve((i+4)/5) )%mod;
	ret=(ret*solve((i+9)/10) )%mod;
	return ret;
}

lli gcd(lli a,lli b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	cin>>t;

	dp[0]=1;
	dp[1]=1;
	dp[2]=1;
	for(lli i=3;i<=10;i++) {
		dp[i]=dp[i-1];
		if(i%2==1 && i!=9)
			dp[i]*=i;
	}

	while(t--) {
		cin>>n;

		lli val=solve(n);
		// cout<<n<<" "<<val<<endl;

		if(val==0) {
			printf("0\n");
			continue;
		}

		lli ans=-1;

		for(lli i=1;i<=5;i++) {
			for(lli j=1;j<=5;j++) {
				if(gcd(i,j)!=1)
					continue;
				ans=max(ans,power(i*val,j*val));
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}