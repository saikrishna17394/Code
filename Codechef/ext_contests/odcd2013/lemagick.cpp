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
int t,dp[501][501];
char s1[501],s2[501];


int main() {
	inp(t);

	while(t--) {
		scanf("%s",s1);
		scanf("%s",s2);
		int len1=strlen(s1);
		int len2=strlen(s2);

		for(int i=0;i<=len1;i++)
			dp[i][0]=i;
		for(int j=0;j<=len2;j++)
			dp[0][j]=j;

		for(int i=1;i<=len1;i++) {
			for(int j=1;j<=len2;j++) {
				if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1];
				else {
					dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
					dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
				}
			}
		}
		printf("%d\n", dp[len1][len2]);
	}

	return 0;
}