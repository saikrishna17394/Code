#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
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

lli t,m,n;
lli dp[101][101],ncr[101][101];

int main() {
	// freopen("inp","r",stdin);
	// freopen("A-small-practice.in", "r", stdin);	
	freopen("A-large-practice.in", "r", stdin);

	freopen("out.txt", "w", stdout);

	inp(t);

	memset(ncr,0,sizeof ncr);
	ncr[0][0]=1;
	for(int i=1;i<101;i++) {
		ncr[i][0]=1;
		for(int j=1;j<=i;j++)
			ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
	}

	for(int i=1;i<101;i++)
		dp[1][i]=1;

	for(lli i=2;i<101;i++) {
		for(lli j=i;j<101;j++) {
			dp[i][j]=0;
			
			for(lli k=0;k<=(j-i);k++) {
				dp[i][j]+=(dp[i-1][j-k-1]*ncr[j-1][k])%mod;
				dp[i][j]%=mod;
			}


			dp[i][j]*=i;
			dp[i][j]%=mod;
		}
	}
	for(int a=1;a<=t;a++) {
		inp(m);
		inp(n);

		printf("Case #%d: %lld\n",a, dp[m][n]);

	}


	return 0;
}