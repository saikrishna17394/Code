#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


int n,M;
int A[110];
ii B[110];
int dp[110][4000];

map<int,int> m;
int idx;

void solve(int num) {

	int val=num;
	for(int i=2;i*i<=num;i++) {
		while(val%i==0) {
			val/=i;
			m[i]=1;
		}
	}
	if(val!=1)
		m[val]=1;
}

int g[102][102];
vector<int> v[102];
int vis[102];
int par[102];

bool dfs(int u,int dad) {
	vis[u]=1;
	par[u]=dad;

	if(u==(n+1))
		return true;

	for(int i=0;i<v[u].size();i++) {
		int nxt=v[u][i];

		if(g[u][nxt]>0 && vis[nxt]==0) {
			if(dfs(nxt,u))
				return true;
		}
	}
	return false;
}


int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n>>M;

	for(int i=1;i<=n;i++) {
		cin>>A[i];
		solve(A[i]);
	}

	for(int i=0;i<M;i++) {
		cin>>B[i].first>>B[i].second;
		if(B[i].first%2==0)
			swap(B[i].first,B[i].second);

		v[B[i].first].push_back(B[i].second);
		v[B[i].second].push_back(B[i].first);
	}

	for(int i=1;i<=n;i+=2) {
		v[0].push_back(i);
		v[i].push_back(0);
	}

	for(int i=2;i<=n;i+=2) {
		v[n+1].push_back(i);
		v[i].push_back(n+1);
	}

	idx=m.size();

	for(int i=1;i<=n;i++) {
		map<int,int>::iterator it=m.begin();

		for(int j=0;j<idx;j++) {
			dp[i][j]=0;
			while(A[i]%(it->first)==0) {
				A[i]/=(it->first);
				dp[i][j]++;
			}
			it++;
		}
	}

	// sort(B,B+M);

	int ans=0;

	for(int j=0;j<idx;j++) {

		for(int i=1;i<=n;i+=2) {
			g[0][i]=dp[i][j];
			g[i][0]=0;
		}
		for(int i=2;i<=n;i+=2) {
			g[i][n+1]=dp[i][j];
			g[n+1][i]=0;
		}

		for(int i=0;i<M;i++) {
			int a=B[i].first;
			int b=B[i].second;

			g[a][b]=min(dp[a][j],dp[b][j]);
			g[b][a]=0;
		}


		while(1) {
			memset(vis,0,sizeof vis);

			if(!dfs(0,-1))
				break;
			// ans++;

			int ver=n+1;

			int val=99999;

			while(par[ver]!=-1) {
				val=min(val,g[par[ver]][ver]);
				ver=par[ver];
			}
			ans+=val;

			ver=n+1;
			while(par[ver]!=-1) {
				g[par[ver]][ver]-=val;
				g[ver][par[ver]]+=val;
				ver=par[ver];
			}			
		}
	}
	cout<<ans<<endl;
	return 0;
}