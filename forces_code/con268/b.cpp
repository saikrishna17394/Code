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

int n,A[100000],a,b;
vector<int> g[100000];
map<int,int> m;
int vis[100000],ans[100000];
set<int> s[100000];
int idx=0;

void dfs(int i) {
	// cout<<i<<endl;
	vis[i]=1;
	s[idx].insert(A[i]);

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0)
			dfs(g[i][j]);
	}
	return ;
}

int main() {
	cin>>n>>a>>b;

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		m[A[i]]=i;
	}


	for(int i=0;i<n;i++) {
		if(m.find(a-A[i])==m.end()) {
			if(m.find(b-A[i])==m.end()) {
				printf("NO\n");
				return 0;
			}
			g[m[A[i]]].push_back(m[b-A[i]]);
			g[m[b-A[i]]].push_back(m[A[i]]);
		}
		else if(m.find(b-A[i])==m.end()) {
			g[m[A[i]]].push_back(m[a-A[i]]);
			g[m[a-A[i]]].push_back(m[A[i]]);
		}
		else {
			g[m[A[i]]].push_back(m[b-A[i]]);
			g[m[b-A[i]]].push_back(m[A[i]]);
			g[m[A[i]]].push_back(m[a-A[i]]);
			g[m[a-A[i]]].push_back(m[A[i]]);
		}
	}

	for(int i=0;i<n;i++) {
		if(vis[i]==0) {
			// cout<<idx<<" bro\n";
			dfs(i);
			idx++;
		}
	}

	for(int i=0;i<idx;i++) {
		bool canA=true,canB=true;
		// cout<<idx<<" bro\n";
		for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++) {
			// cout<<
			if(s[i].find(a-*it)==s[i].end())
				canA=false;
			if(s[i].find(b-*it)==s[i].end())
				canB=false;
		}

		if(canA==true) {
			for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++) {
				ans[m[*it]]=0;
			}
		}
		else if(canB==true) {
			for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++) {
				ans[m[*it]]=1;
			}
		}
		else {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");

	return 0;
}