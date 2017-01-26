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
#define lim 100001

using namespace std;

int par[lim],A[lim],n,m,st[lim],end[lim],sz[lim];
vector<int> g[lim];
vector<ii> solve[lim];
pair<int,ii> q[lim];
int child[lim]={0},tim=0,ans[lim];

void dfs(int i) {
	st[i]=++tim;

	for(int j=0;j<g[i].size();j++) {
		dfs(g[i][j]);
	}
	end[i]=++tim;
}

int root(int i) {
	if(par[i]==i)
		return i;
	return par[i]=root(par[i]);
}

void join(int a,int b) {
	if(sz[a]>=sz[b]) {
		sz[a]+=sz[b];
		par[b]=a;
	}
	else {
		sz[b]+=sz[a];
		par[a]=b;
	}
}

int main() {
	cin>>n>>m;
	int t,x,y;

	int idx=1;

	for(int i=0;i<m;i++) {
		scanf("%d",&t);
		q[i].first=t;

		if(t==1) {
			scanf("%d %d",&x,&y);
			q[i].second.first=x;
			q[i].second.second=y;
			g[y].push_back(x);
			child[x]=1;
		}
		else if(t==2) {
			scanf("%d",&x);
			A[idx++]=x;
		}
		else {
			scanf("%d %d",&q[i].second.first,&q[i].second.second);
			solve[q[i].second.second].push_back(ii(q[i].second.first,i));
		}
	}

	for(int i=1;i<=n;i++) {
		if(child[i]==0) {
			dfs(i);
		}
		par[i]=i;
		sz[i]=1;
	}

	idx=1;
	for(int i=0;i<m;i++) {
		t=q[i].first;
		// cout<<t<<" :\n";
		if(t==1) {
			join(root(q[i].second.first),root(q[i].second.second));
		}
		else if(t==2) {
			x=A[idx];
			for(int i=0;i<solve[idx].size();i++) {
				y=solve[idx][i].first;
				if(root(x)!=root(y))
					ans[solve[idx][i].second]=0;
				else {
					if(st[y]<=st[x] && end[x]<=end[y])
						ans[solve[idx][i].second]=1;
					else
						ans[solve[idx][i].second]=0;
				}
			}
			idx++;
		}
		else {
			if(ans[i]==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}