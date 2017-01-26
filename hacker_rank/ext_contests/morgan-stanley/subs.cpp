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

lli n,k;
lli dp[50000][101],A[50000];

int main() {
	memset(dp,0,sizeof dp);

	inp(n);
	inp(k);

	for(int i=0;i<n;i++) {
		inp(A[i]);
	}

	dp[0][A[0]%k]=1;
	lli ans=dp[0][0];

	for(int i=1;i<n;i++) {

		for(int j=0;j<=k;j++) {
			dp[i][(j+A[i])%k]+=dp[i-1][j];
		}
		dp[i][A[i]%k]++;
		ans+=dp[i][0];
	}

	cout<<ans<<endl;
	return 0;
}