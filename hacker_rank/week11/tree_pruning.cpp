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
#define ii pair<long long int,int>

#define mod 1000000007
#define inf (lli)1e16
#define lim 100001

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int vis[lim],a,b,par[lim],n,k;
lli A[lim],dp[lim][201],dp1[lim][201];
vector<int> g[lim];

void dfs(int i) {
	// dp[i][0]=A[i];
	vis[i]=1;

	lli B[lim];

	for(int j=0;j<=k;j++) {
		B[j]=A[i];
		dp[i][j]=A[i]
	}

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==1) 
			continue;
		
		par[g[i][j]]=i;
		dfs(g[i][j]);

		dp[i][0]+=dp[g[i][j]][0];

		for(int a=1;a<=k;a++)
			dp[i][a]=max(dp[i][a],dp[i][0]);


	}



}

void dfs1(int i) {
	vis[i]=1;
	s.erase(ii(dp[i],i));

	for(int j=0;j<g[i].size();j++) {
		if(g[i][j]==par[i])
			continue;
		if(vis[g[i][j]]==0)
			dfs1(g[i][j]);
	}
}

int main() {
	cin>>n>>k;

	for(int i=1;i<=(int)n;i++)
		inp(A[i]);

	for(int c=1;c<(int)n;c++) {
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	memset(vis,0,sizeof vis);
	memset(par,-1,sizeof par);

	dfs(1);
	s.erase(ii(dp[1],1));

	lli ans=dp[1];
	memset(vis,0,sizeof vis);
	while(k--) {
		if(s.empty())
			break;
		set<ii>::iterator it=s.begin();

		if(it->first>=0)
			break;
		ans-=(it->first);
		dfs1(it->second);
	}

	printf("%lld\n", ans);
	return 0;
}