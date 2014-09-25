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

int t,n,A[200000];

lli ans,dp[101][200],diff[101],pow2[200001];


int main() {
	inp(t);

	pow2[0]=1;

	for(int i=1;i<200001;i++)
		pow2[i]=(2*pow2[i-1])%mod;


	while(t--) {
		inp(n);
		for(int i=0;i<n;i++)
			inp(A[i]);

		memset(dp,0,sizeof dp);
		ans=1;
		for(int i=n-1;i>=0;i--) {
			ans++;
			// ans%=mod;

			

			for(int j=1;j<=100;j++) {
				ans+=dp[j][j-A[i]+99];
				diff[j]=dp[j][j-A[i]+99];
			}
			ans%=mod;

			for(int j=1;j<=100;j++) {
				dp[A[i]][j-A[i]+99]+=diff[j];
				dp[A[i]][j-A[i]+99]%=mod;
				dp[A[i]][A[i]-j+99]++;
				dp[A[i]][A[i]-j+99]%=mod;
			}

			// cout<<i<<" "<<ans<<endl;
		}

		// cout<<ans<<endl;
		ans=pow2[n]-ans;

		ans%=mod;

		if(ans<0)
			ans+=mod;
		ans%=mod;

		printf("%lld\n", ans);

	}


	return 0;
}