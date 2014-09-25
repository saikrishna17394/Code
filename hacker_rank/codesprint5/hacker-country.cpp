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


int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int n,g[500][500],ans,b,val,a;
int dp[500][501];

int main() {
	inp(n);
	ans=1000000;
	b=1;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			inp(g[i][j]);

	memset(dp,0,sizeof dp);

	for(int k=1;k<=n;k++) {
		for(int i=0;i<n;i++) {
			dp[i][k]=inf;
			for(int j=0;j<n;j++) {
				if(i==j)
					continue;
				dp[i][k]=min(dp[i][k],dp[j][k-1]+g[j][i]);
			}
			// cout<<i<<" "<<k<<" "<<dp[i][k]<<endl;
		}
	}

	for(int i=0;i<n;i++) {
		val=0;
		a=1;
		for(int k=0;k<n;k++) {
			if(((dp[i][n]-dp[i][k])*a)>val*(n-k)) {
				val=dp[i][n]-dp[i][k];
				a=n-k;
			}
		}
		// cout<<val<<" "<<a<<endl;
		// cout<<ans<<" "<<b<<endl;
		if(ans*a>val*b) {
			ans=val;
			b=a;
		}
	}
	a=gcd(ans,b);
	ans/=a;
	b/=a;

	printf("%d/%d\n",ans,b );
	return 0;
}