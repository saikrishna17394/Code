#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
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
lli n,A[1000],dp[1000][1000],B[1000];

lli ans(int i,int j) {
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i==j)
		return A[i];

	lli val=B[j-1];
	if(i)
		val-=B[i-1];

	lli ret=max(A[i]+(B[j]-B[i]-ans(i+1,j)),A[j]+(val-ans(i,j-1)));
	dp[i][j]=ret;
	return ret;
}

int main() {
	inp(n);
	inp(A[0]);
	B[0]=A[0];

	for(int i=1;i<n;i++) {
		inp(A[i]);
		B[i]=A[i]+B[i-1];
	}

	if(n==1) {
		printf("%lld 0\n", A[0]);
		return 0;
	}
	memset(dp,-1,sizeof dp);

	lli val=ans(0,n-1);

	printf("%lld %lld\n",val,B[n-1]-val);

	return 0;
}