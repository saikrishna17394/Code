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

#define mod 1000000007
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

lli dp[101][101],A[101][101];
lli t,m,n;

int main() {
	memset(A,0,sizeof A);

	A[0][0]=1;

	for(int i=1;i<101;i++) {
		A[i][0]=1;
		for(int j=1;j<=i;j++)
			A[i][j]=(A[i-1][j]+A[i-1][j-1])%mod;
	}


	for(int j=1;j<101;j++) {
		dp[1][j]=1;
	}

	for(int i=2;i<101;i++) {
		for(int j=i;j<101;j++) {
			dp[i][j]=0;
			for(int k=1;k<=(j-i+1);k++) {
				dp[i][j]+=(A[j][k]*dp[i-1][j-k])%mod;
			}
			dp[i][j]%=mod;
		}
	}

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(m);
		inp(n);
		printf("Case #%d: %lld\n",a, dp[m][n]);
	}
	return 0;
}