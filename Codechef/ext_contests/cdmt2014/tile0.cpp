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

int dp[1000001],t,n;

int main() {
	dp[1]=1;
	dp[2]=2;

	for(int i=3;i<1000001;i++)
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	inp(t);

	while(t--) {
		inp(n);
		printf("%d\n", dp[n]);
	}

	return 0;
}