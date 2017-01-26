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

int n,m;
string s;

vector<int> g[400];
int vis[400]={0};

void dfs(int i) {
	// cout<<i<<endl;
	vis[i]=1;

	for(int j=0;j<g[i].size();j++)
		if(vis[g[i][j]]==0)
			dfs(g[i][j]);
}

int main() {
	cin>>n>>m;
	cin>>s;

	for(int i=0;i<n;i++) {
		if(s[i]=='<') {
			for(int j=m-1;j>0;j--) {
				// cout<<i*n+j<<" ";
				g[i*m+j].push_back(i*m+j-1);
			}
			// cout<<endl;
		}
		else {
			for(int j=0;j<(m-1);j++) {
				// cout<<i*n+j<<" ";
				g[i*m+j].push_back(i*m+j+1);
			}
			// cout<<endl;
		}
	}

	cin>>s;
	for(int j=0;j<m;j++) {
		if(s[j]=='^') {
			for(int i=n-1;i>0;i--)
				g[i*m+j].push_back((i-1)*m+j);
		}
		else {
			for(int i=0;i<(n-1);i++)
				g[i*m+j].push_back((i+1)*m+j);
		}
	}

	// for(int i=0;i<(n*m);i++) {
	// 	cout<<"g "<<i<<" : ";
	// 	for(int j=0;j<g[i].size();j++)
	// 		cout<<g[i][j]<<" ";
	// 	cout<<endl;
	// }

	for(int i=0;i<(n*m);i++) {
		memset(vis,0,sizeof vis);
		// cout<<"dfs : "<<endl;
		dfs(i);

		for(int j=0;j<(n*m);j++) {
			if(vis[j]==0) {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}