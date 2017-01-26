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


int n;
vector<int> g[lim];
lli dp[lim];
int ht[lim];
int help[lim];


lli dfs(int i,int par) {
	dp[i]=1;

	lli val=0;
	int num=0;

	for(int j=0;j<g[i].size();j++) {
		int nxt=g[i][j];
		if(dp[nxt]==-1) {
			dp[i]+=dfs(nxt,i);
			val++;
			num=max(num,ht[nxt]);
		}
	}
	ht[i]=num+1;

	if(val==1)
		return dp[i];

	for(int j=0;j<ht[i];j++) {
		help[j]=0;
	}

	dfs1(i,par,0);

	dp[i]=0;

	for(int j=0;j<ht[i];j++) {
		lli num=(lli)(help[j]);
		dp[i]+=num*num;
	}

	return dp[i];
}

int main() {
	inp(n);

	for(int i=1;i<n;i++) {
		int a,b;
		inp(a);
		inp(b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	memset(dp,-1,sizeof dp);
	lli ans=dfs(0,-1);

	for(int i=0;i<n;i++) {
		if(i>0)
			printf(" ");
		printf("%lld", dp[i]);
	}
	printf("\n");
	return 0;
}