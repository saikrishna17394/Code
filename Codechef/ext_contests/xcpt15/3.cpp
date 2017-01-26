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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


lli dp[101];
int t,n;

int main() {
	dp[0]=1;
	dp[1]=1;

	for(lli i=2;i<(lli)101;i++) {
		dp[i]=0;
		for(lli j=0;j<i;j++)
			dp[i]+=dp[j]*dp[i-j-1];
		// cout<<i<<" "<<dp[i]<<endl;
	}
	inp(t);

	while(t--) {
		inp(n);
		cout<<dp[n]<<endl;
	}	

	return 0;
}