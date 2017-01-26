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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,m,a,b,vis[2000],cmp[2000],idx;
vector<int> g[2000],g1[2000],v;

void dfs(int i) {
	vis[i]=1;

	for(int j=0;j<g[i].size();j++)
		if(vis[g[i][j]]==0)
			dfs(g[i][j]);

	v.push_back(i);
}


void dfs1(int i) {
	vis[i]=1;
	cmp[i]=idx;
	// cout<<i<<" "<<cmp[i]<<endl;

	for(int j=0;j<g1[i].size();j++)
		if(vis[g1[i][j]]==0)
			dfs1(g1[i][j]);
}


bool dfs2(int i) {
	vis[i]=1;

	for(int j=0;j<g[i].size();j++)
		if(vis[g[i][j]]==0) {
			if(g[i][j]==n)
				return false;
			if(!dfs2(g[i][j]))
				return false;
		}

	return true;
}

int main() {

	while(scanf("%d %d",&n,&m)!=EOF) {
	
		for(int i=0;i<2*n;i++) {
			g[i].clear();
			g1[i].clear();
		}

		while(m--) {	
			inp(a);
			inp(b);
			a*=-1;

			// cout<<"w "<<a<<" "<<b<<endl;
			if(a<0)
				a=abs(a)+n-1;
			else
				a--;
			if(b<0)
				b=abs(b)+n-1;
			else
				b--;

			g[a].push_back(b);		
			g1[b].push_back(a);

			if(a>=n)
				a-=n;
			else
				a+=n;

			if(b>=n)
				b-=n;
			else
				b+=n;

			g[b].push_back(a);
			g1[a].push_back(b);

		}

		v.clear();

		memset(vis,0,sizeof vis);
	
		for(int i=0;i<2*n;i++)
			if(vis[i]==0)
				dfs(i);
		
		memset(vis,0,sizeof vis);
		idx=0;

		for(int i=v.size()-1;i>=0;i--)
			if(vis[v[i]]==0) {
				dfs1(v[i]);
				idx++;
			}

		bool ok=true;
		for(int i=0;i<n;i++) {
			if(cmp[i]==cmp[n+i]) {
				printf("no\n");
				ok=false;
				break;
			}
		}

		if(!ok)
			continue;
		// This is checking if there is a path from 0 to n
		memset(vis,0,sizeof vis);
		if(dfs2(0))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}