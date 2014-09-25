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
#include <ctime>

#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,a,b,sz[101],vis[101];

vector<int> g[101];

void dfs(int i) {
	sz[i]=1;
	vis[i]=1;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0) {
			dfs(g[i][j]);
			sz[i]+=sz[g[i][j]];
		}
	}
	// cout<<i<<" "<<sz[i]<<endl;
}

double f(int i) {
	double ret=1,val;
	ret/=(double)sz[i];
	vis[i]=1;

	val=ret;
	val=1.0-val;

	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0) {
			ret=ret+val*f(g[i][j]);
		}
	}
	return ret;

}
int main() {
	inp(n);

	// cout<<n<<endl;
	for(int i=1;i<n;i++) {
		inp(a);
		inp(b);
		// cout<<a<<" d "<<b<<endl;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	double ans=0;
	memset(vis,0,sizeof vis);

	dfs(1);

	// double ans=0;

	memset(vis,0,sizeof vis);
	for(int i=0;i<g[1].size();i++) {
		ans+=f(g[1][i]);
	}
	ans*=(double)(n-1);
	ans/=(double)(n);
	
	int num=ans;
	printf("%d\n", num);

	return 0;
}