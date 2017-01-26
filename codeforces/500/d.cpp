#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int n,par[lim];
vector<ii> g[lim];
int B[lim][3];
int cnt[lim]={0},vis[lim];
double ans;



void dfs(int u,int nxt) {
	cnt[u]=1;
	vis[u]=1;
	par[u]=nxt;

	for(int j=0;j<g[u].size();j++) {
		int v=g[u][j].first;
		double wt=(double)g[u][j].second;

		if(vis[v]==0) {
			dfs(v,u);
			cnt[u]+=cnt[v];
			double val=(double)(cnt[v]);
			val*=(double)(n-cnt[v]);
			val*=(double)(n-2);
			ans+=(wt*val);
		}
	}
}

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n;

	for(int i=1;i<n;i++) {
		cin>>B[i][0]>>B[i][1]>>B[i][2];

		g[B[i][0]].push_back(ii(B[i][1],B[i][2]));
		g[B[i][1]].push_back(ii(B[i][0],B[i][2]));
	}
	
	memset(vis,0,sizeof vis);
	ans=0;
	dfs(1,-1);

	double den=(double)n;
	den*=(double)(n-1);
	den*=(double)(n-2);
	den/=6.0;

	int q;
	cin>>q;

	while(q--) {
		int r,w;
		cin>>r>>w;
		int a=B[r][0],b=B[r][1];

		if(par[a]==b)
			swap(a,b);

		double val=(double)(cnt[b]);
		val*=(double)(n-cnt[b]);
		val*=(double)(n-2);
		
		ans+=val*(double)(w-B[r][2]);
		B[r][2]=w;
		printf("%.10f\n",ans/den );
	}
	return 0;
}