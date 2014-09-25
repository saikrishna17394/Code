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

#define mod 1000000003
#define inf 999999999
#define lim 100010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int dp[18][1<<18];
int t,n,m,g[18][18],a,b;

int solve(int idx,int mask) {
	// cout<<idx<<" "<<mask<<endl;
	if(idx==n) {
		return 1;
	}
	int &ret=dp[idx][mask];
	if(ret!=-1)
		return ret;

	int val=mask;
	ret=0;
	int val1=1;
	for(int i=0;i<n;i++) {
		if(g[idx][i]==1 && (val&1)==0) {
			ret+=solve(idx+1,mask|val1);
			ret%=mod;
		}
		val1*=2;
		val/=2;
	}
	return ret;
}

int main() {
	inp(t);
	while(t--) {
		inp(n);
		inp(m);
		memset(g,0,sizeof g);
		while(m--) {
			inp(a);
			inp(b);
			g[a][b%n]=1;
		}
		memset(dp,-1,sizeof dp);
		printf("%d\n",solve(0,0));
	}
	return 0;
}