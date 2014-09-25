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
#define ii pair<long long int,long long int>

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
int n,m,a,b,ans2;
vector<int> g[50000];
int A[50000],vis[50000];
lli ans1;

int dfs(int i) {
	vis[i]=1;
	int ret=0;
	if(A[i])
		ret++;
	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0) {
			ret+=dfs(g[i][j]);
		}
	}
	return ret;
}

int dfs1(int i) {
	vis[i]=1;
	int ret=0;
	bool ok=false;

	if(A[i]) 
		ok=true;
	for(int j=0;j<g[i].size();j++) {
		if(vis[g[i][j]]==0) {
			int val=dfs1(g[i][j]);
			if(val)
				ok=true;
			ret+=val;
		}
	}
	if(ok)
		ret++;
	return ret;
}

int main() {
	inp(n);
	inp(m);
	for(int i=0;i<n;i++)
		inp(A[i]);
	while(m--) {
		inp(a);
		inp(b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans1=0;

	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++) {
		if(vis[i]==0) {
			int val=dfs(i);
			ans1+=(lli)val*(lli)(val-1);
		}
	}
	ans1/=2;

	ans2=0;
	memset(vis,0,sizeof vis);
	for(int i=0;i<n;i++) {
		if(A[i]==1 && vis[i]==0) {
			int val=dfs1(i);
			if(val>1)
				ans2+=val;
		}
	}
	printf("%lld %d\n",ans1,ans2 );
	return 0;
}