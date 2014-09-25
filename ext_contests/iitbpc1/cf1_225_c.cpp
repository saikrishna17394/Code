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

int n,m,A[200001],start[200001],end[200001];
int tree[200001]={0},vis[200001]={0},a,b,level[200001];
vector<int> g[200001];

int tim=0;

void dfs(int i) {
	vis[i]=1;

	start[i]=++tim;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0) {
			level[g[i][j]]=level[i]+1;
			dfs(g[i][j]);
		}
	}
	end[i]=tim;
}


void update(int idx,int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int query(int idx) {
	int ret=0;
	while(idx>0) {
		ret+=tree[idx];
		idx-=idx&-idx;
	}
	return ret;
}

int main() {
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++) {
		scanf("%d",&A[i]);
	}

	for(int i=1;i<n;i++) {
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	level[1]=0;

	int x,val;
	while(m--) {
		cin>>a;
		if(a==1) {
			scanf("%d %d",&x,&val);

			if(level[x]%2==0) {
				update(start[x],val);
				update(end[x]+1,-val);
			}
			else {
				update(start[x],-val);
				update(end[x]+1,val);				
			}
		}
		else {
			scanf("%d",&x);
			if(level[x]%2==0) {
				printf("%d\n", A[x]+query(start[x]));
			}
			else {
				printf("%d\n", A[x]-query(start[x]));
			}
		}
	}
	return 0;
}