#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
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
int t,len,dp[5000];
bool A[5000][5000];
string s;

int ans(int i) {
	if(dp[i]!=-1)
		return dp[i];
	if(A[i][len-1]) {
		dp[i]=0;
		return 0;
	}
	int ret=inf;

	for(int a=i;(a+1)<len;a++) {
		if(A[i][a]) {
			ret=min(ret,1+ans(a+1));
		}
	}
	dp[i]=ret;
	return ret;
}

int main() {
	inp(t);

	while(t--) {
		inp(len);
		cin>>s;


		for(int i=0;i<len;i++)
			A[i][i]=1;

		for(int i=0;i<(len-1);i++) {
			if(s[i]==s[i+1])
				A[i][i+1]=1;
			else
				A[i][i+1]=0;
		}

		for(int k=2;k<len;k++) {
			for(int i=0;(i+k)<len;i++) {
				A[i][i+k]=0;
				if(s[i]==s[i+k] && A[i+1][i+k-1])
					A[i][i+k]=1;
			}
		}
		memset(dp,-1,sizeof dp);
		
		printf("%d\n", ans(0)+1);
	}

	return 0;
}