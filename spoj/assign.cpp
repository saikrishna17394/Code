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

lli dp[1<<20];
int A[20][20];
int n;

// first thought of using this function
// Then realised count_zero can be sent as paremter to the ans function itself
// Because of each time count_zero in the "mask" increases by 1 when asked for subproblem

int count_zero(int mask) {
	int val=0;
	for(int i=0;i<n;i++) {
		if(!(mask&1))
			val++;
		mask>>=1;
	}
	return val;
}

lli ans(int i,int mask) {

	if(dp[mask]!=-1)
		return dp[mask];
	
	lli val=0;
	int mask1=mask;


	for(int j=0;j<n;j++) {
		if(A[i][j]&(mask&1)) {
			val+=ans(i+1,mask1^(1<<j));
		}
		mask>>=1;
	}

	dp[mask1]=val;

	return val;
}

int main() {
	int t,lim;

	inp(t);

	while(t--) {
		inp(n);
		memset(dp,-1,sizeof dp);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				inp(A[i][j]);
		

		int mask=1;

		for(int i=0;i<n;i++) {
			if(A[n-1][i])
				dp[mask]=1;
			else
				dp[mask]=0;

			mask<<=1;
		}
		
		mask=1<<n;
		mask--;

		printf("%lld\n", ans(0,mask));

	}

	return 0;
}