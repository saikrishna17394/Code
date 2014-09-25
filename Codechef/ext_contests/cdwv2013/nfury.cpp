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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int dp[1001],t,n;
	dp[0]=0;
	dp[1]=1;

	for(int i=2;i<=1000;i++) {
		dp[i]=i;
		for(int j=1;j*j<=i;j++)
			dp[i]=min(dp[i],1+dp[i-j*j]);
	}
	inp(t);
	while(t--) {
		inp(n);
		printf("%d\n", dp[n]);
	}
	return 0;
}