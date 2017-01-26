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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999
#define lim 5010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,k;
string s1,s2;
int dp[lim][lim];

int main() {
	inp(n);
	inp(k);
	cin>>s1>>s2;

	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i==0 || j==0) {
				if((i+k)<=n && (j+k)<=n)
					dp[i][j]=i*k+(j+1);
				else
					dp[i][j]=0;
			}
			else {
				dp[i][j]=dp[i-1][j-1];
				if((i+k)<=n && (j+k)<=n)
					dp[i][j]+=i*k+(j+1);
				if((i-k)>=0 && (j-k)>=0)
					dp[i][j]-=((i-k)*k+(j-k+1));
				dp[i][j]+=mod;
				dp[i][j]%=mod;
			}
			if(s1[i]==s2[j])
				ans=(ans+dp[i][j])%mod;
			// cout<<i+1<<" "<<j+1<<" "<<dp[i][j]<<" : "<<ans<<endl;
		}
	}

	printf("%d\n", ans);

	return 0;
}