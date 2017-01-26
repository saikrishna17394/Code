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

int n,A[2000][2000],par[2000],sz[2000],vis[2000];
vector<int> g[2000];
pair<int,ii> B[2000*2000];

bool dfs(int i,int val,int rot) {
	vis[i]=1;
	if(val!=A[rot][i])
		return false;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0) {
			if(!dfs(g[i][j],val+A[i][g[i][j]],rot))
				return false;
		}
	}
	return true;
}

int root(int i) {
	if(par[i]==i)
		return i;
	return par[i]=root(par[i]);
}

void join(int a,int b) {
	if(sz[a]>=sz[b]) {
		par[b]=a;
		sz[a]+=sz[b];
	}
	else {
		par[a]=b;
		sz[b]+=sz[a];
	}
}

int main() {
	cin>>n;

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&A[i][j]);
			if(i!=j && A[i][j]==0) {
				printf("NO\n");
				return 0;
			}
			if(i==j && A[i][j]!=0) {
				printf("NO\n");
				return 0;				
			}
		}
	}

	int idx=0,cnt;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if(A[i][j]!=A[j][i]) {
				printf("NO\n");
				return 0;
			}
			B[idx++]=make_pair(A[i][j],ii(i,j));
		}
	}
	cnt=idx;
	sort(B,B+cnt);

	for(int i=0;i<n;i++) {
		par[i]=i;
		sz[i]=1;
	}

	idx=0;
	int val=0;
	while(idx<cnt) {
		ii p=B[idx].second;
		// cout<<"w "<<p.first<<" "<<p.second<<endl;
		if(val==n-1)
			break;

		int a=root(p.first);
		int b=root(p.second);
		// cout<<"w1 "<<a<<" "<<b<<endl;
		if(a!=b) {
			val++;
			g[p.first].push_back(p.second);
			g[p.second].push_back(p.first);
			// cout<<p.first<<" "<<p.second;
			join(a,b);
		}
		idx++;
	}

	for(int i=0;i<n;i++) {
		memset(vis,0,sizeof vis);
		if(!dfs(i,0,i)) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}