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
#define lim 10000000

using namespace std;

int n,g[2001][2001];

pair<int,ii > A[2000001];
int par[2000],sz[2000];
ii ans[2000];

int root(int i) {
	if(par[i]==i)
		return i;
	return par[i]=root(par[i]);
}

void join(int i,int j) {
	int a=root(i),b=root(j);

	if(sz[a]>=sz[b]) {
		par[b]=a;
		sz[a]+=sz[b];
	}
	else {
		par[a]=b;
		sz[b]+=sz[a];
	}
}

vector<int> g1[2000];

int vis[2000];
lli B[2000];

void dfs(int i,lli val) {
	B[i]=val;
	vis[i]=1;
	for(int j=0;j<g1[i].size();j++) {
		if(vis[g1[i][j]]==0) {
			dfs(g1[i][j],(lli)g[i][g1[i][j]]+val);
		}
	}
}

int main() {

	while(scanf("%d",&n)!=EOF) {
		int idx=0;
		for(int i=0;i<n;i++) {
			par[i]=i;
			sz[i]=1;
			for(int j=0;j<n;j++) {
				scanf("%d",&g[i][j]);
				if(i<j)
					A[idx++]=make_pair(g[i][j],ii(i,j));
			}
			g1[i].clear();
		}

		sort(A,A+idx);

		bool ok=true;
		int val=0;

		for(int i=0;i<idx;i++) {
			ii p=A[i].second;

			int a=root(p.first),b=root(p.second);
			if(a!=b) {
				join(a,b);
				ans[val++]=p;
				g1[p.first].push_back(p.second);
				g1[p.second].push_back(p.first);
			}

			if(val==n-1)
				break;
		}

		int num=inf;

		ok=false;
		for(int i=0;i<n;i++) {
			memset(vis,0,sizeof vis);
			dfs(i,0);
			for(int j=0;j<n;j++) {
				if((lli)g[i][j]<B[j]) {
					if(g[i][j]<num) {
						num=g[i][j];
						if(!ok) {
							val++;
							ok=true;
						}
						ans[val-1]=ii(i,j);
					}
				}
			}
		}
		if(!ok)
			ans[val++]=ans[0];

		for(int i=0;i<n;i++)
			printf("%d %d %d\n",ans[i].first+1,ans[i].second+1,g[ans[i].first][ans[i].second] );
		printf("\n");
	}


	return 0;
}