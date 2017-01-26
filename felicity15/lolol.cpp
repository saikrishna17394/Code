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


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t;
string s;
lli dp[1000010][2];

int main() {
	inp(t);

	while(t--) {
		cin>>s;
		memset(dp,0,sizeof dp);
		
		lli ans=0;

		for(int i=0;i<s.length();i++) {
			if(i>0) {
				dp[i][0]=dp[i-1][0];
				dp[i][1]=dp[i-1][1];
			}

			if(s[i]=='L') {
				if(i>0)
					ans+=dp[i-1][1];
				dp[i][0]++;
			}
			else {
				if(i>0)
					dp[i][1]+=dp[i-1][0];
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}