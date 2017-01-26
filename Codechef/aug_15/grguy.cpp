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

#define mod 1000000007
#define inf 999999999
#define lim 200010
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
string s1,s2;
int dp[lim][2];

int main() {
	inp(t);

	while(t--) {
		int ans=0;
		cin>>s1>>s2;

		if(s1[0]=='#')
			dp[0][0]=inf;
		else
			dp[0][0]=0;

		if(s2[0]=='#')
			dp[0][1]=inf;
		else
			dp[0][1]=0;

		for(int i=1;i<s1.length();i++) {
			dp[i][0]=inf;
			dp[i][1]=inf;

			if(s1[i]=='.') {
				if(s1[i-1]=='.')
					dp[i][0]=min(dp[i][0],dp[i-1][0]);
				if(s2[i-1]=='.')
					dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
			}
			if(s2[i]=='.') {
				if(s1[i-1]=='.')
					dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
				if(s2[i-1]=='.')
					dp[i][1]=min(dp[i][1],dp[i-1][1]);
			}
		}

		ans=min(dp[s1.length()-1][0],dp[s1.length()-1][1]);

		if(ans==inf) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
			printf("%d\n", ans);
		}
	}

	return 0;
}