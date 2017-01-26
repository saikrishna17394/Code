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
#define lli long long int
#define ii pair<int,int>

#define mod 5000000
#define inf 999999999
#define lim 1000001
#define LN 18
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,m,A[1001],vis[1001];
vector<int> g[1001];

vector<int> v;
vector<int> v1;

void dfs(int cur) {
	vis[cur]=1;
	v.push_back(A[cur]);
	v1.push_back(cur);

	for(int j=0;j<g[cur].size();j++) {
		if(vis[g[cur][j]]==0)
			dfs(g[cur][j]);
	}
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<n;i++) {
			inp(A[i]);
			g[i].clear();
		}

		int i,j;

		while(m--) {
			inp(i);
			inp(j);
			i--;
			j--;
			g[i].push_back(j);
			g[j].push_back(i);

		}

		memset(vis,0,sizeof vis);
		for(int i=0;i<n;i++) {
			if(vis[i]==0) {
				v.clear();
				v1.clear();
				dfs(i);

				sort(v.begin(),v.end());
				sort(v1.begin(),v1.end());

				for(int j=0;j<v.size();j++) {
					// cout<<v[j]<<" "<<v1[j]<<endl;
					A[v1[j]]=v[j];
				}
			}
		}

		for(int i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n");
	}

	return 0;
}