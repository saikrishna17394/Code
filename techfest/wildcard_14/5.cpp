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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 10000
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli dp[lim+1][lim+1];

int main() {

	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(int i=1;i<=lim;i++) {
		dp[i][0]=1;
		for(int j=1;j<=i;j++)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
	}

	// cout<<dp[5][2]<<" "<<dp[6][3]<<endl;
	lli ans=0,num;
	// cout<<lim<<endl;
	ans=0;
	for(int i=2300;i<=lim;i++) {
		for(int j=2700;j<=lim;j++) {
			int k=lim-i-j;
			if(k<1100)
				break;
			// cout<<i<<" "<<j<<" "<<k<<endl;
			num=dp[lim][i]*dp[lim-i][j];
			num%=mod;
			ans=(ans+num)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}