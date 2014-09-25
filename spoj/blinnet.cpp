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

int t,n,par[10001],sz[10001],x,y,a,cnt;
lli ans;
char ch[11];

set<pair<lli,ii> > m;

void unio (int a,int b) {
	if(sz[a]>=sz[b]) {
		sz[a]+=sz[b];
		par[b]=a;
		return;
	}
	sz[b]+=sz[a];
	par[a]=b;
}

int root(int i) {
	if(par[i]==i)
		return i;

	return par[i]=root(par[i]);
}

int main() {
	inp(t);

	while(t--) {
		inp(n);

		m.clear();

		for(int i=1;i<=n;i++) {
			scanf("%s",ch);

			par[i]=i;
			sz[i]=1;

			inp(a);

			while(a--) {
				inp(x);
				scanf("%lld",&ans);
				if(x>i)
					m.insert(make_pair(ans,ii(i,x)));
			}
		}

		ans=0;
		cnt=0;


		for(set<pair<lli,ii> >::iterator it =m.begin();it!=m.end();it++) {
			x=(*it).second.first;
			y=(*it).second.second;


			x=root(x);
			y=root(y);
			if(x!=y) {
				cnt++;
				ans+=(*it).first;
				unio(x,y);
			}

			if(cnt==n-1)
				break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}