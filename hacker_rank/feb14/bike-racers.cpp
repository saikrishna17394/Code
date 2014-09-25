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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli g[250][250],l,r,n,m,k,cur;
ii bikers[250],bikes[250];

int vis[250],match[250];

bool dfs(int i) {

	for(int j=0;j<m;j++) {
		if(vis[j] || g[i][j]>cur)
			continue;
		vis[j]=1;

		if(match[j]==-1 || dfs(match[j])) {
			match[j]=i;
			return true;
		}
	}

	return false;
}

int main() {
	inp(n);
	inp(m);
	inp(k);

	for(int i=0;i<n;i++) {
		inp(bikers[i].first);
		inp(bikers[i].second);
	}

	for(int i=0;i<m;i++) {
		inp(bikes[i].first);
		inp(bikes[i].second);
	}

	l=0;
	r=0;

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			g[i][j]=(bikers[i].first-bikes[j].first)*(bikers[i].first-bikes[j].first);
			g[i][j]+=(bikers[i].second-bikes[j].second)*(bikers[i].second-bikes[j].second);
			r=max(r,g[i][j]);
		}
	}

	while(l<=r) {
		if(l==r)
			break;
		// cout<<l<<" "<<r<<endl;
		cur=(l+r)/2;

		int ans=0;
		memset(match,-1,sizeof match);
		for(int i=0;i<n;i++) {
			memset(vis,0,sizeof vis);
			if(dfs(i))
				ans++;
		}

		if(ans>=k) {
			r=cur;
		}
		else {
			l=cur+1;
		}

	}
	printf("%lld\n", l);

	return 0;
}