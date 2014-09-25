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

inline bool inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
	if(ch=='\n' || ch==EOF)
		return true;
	return false;
}

lli n,q,A[100000],x,dp[100000];

int main() {
	inp(n);
	inp(q);

	for(int i=0;i<n;i++)
		inp(A[i]);

	sort(A,A+n);

	dp[0]=A[0];
	for(int i=1;i<n;i++) {
		dp[i]=dp[i-1]+A[i];
	}

	
	while(q--) {
		inp(x);
		printf("%lld\n", dp[x-1]%mod);
	}


	return 0;
}