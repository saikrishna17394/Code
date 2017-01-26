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

vector<int> g[100001];
int t,n,k,dp[100001];


void dfs(int u) {

	if(g[u].size()==0) {
		dp[u]=0;
		return;
	}

	// set<int> s;
	int val=1;

	for(int j=0;j<g[u].size();j++) {
		int v=g[u][j];
		dfs(v);
		val&=dp[v];
		// s.insert(dp[v]);
	}

	dp[u]=val^1;

}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(k);

		for(int i=1;i<=n;i++)
			g[i].clear();

		for(int i=1;i<n;i++) {
			int a,b;
			inp(a);
			inp(b);
			g[a].push_back(b);
		}

		dfs(1);

		if(k%2==0)
			dp[1]=0;

		if(dp[1]==0)
			printf("Babri\n");
		else
			printf("Eli\n");
	}

	return 0;
}
