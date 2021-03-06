#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000000
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
lli par[100001],sz[100001];

int root(int i) {
	if(par[i]==i)
		return i;
	par[i]=root(par[i]);
	return par[i];
}
void union1(int a,int b){
	if(sz[a]>=sz[b]) {
		sz[a]+=sz[b];
		par[b]=a;
	}
	else {
		sz[b]+=sz[a];
		par[a]=b;
	}
}

int main() {
	lli n,m,a,b,c,ans,x,y,val=0;
	pair<lli,ii> A[100000];
	inp(n);
	inp(m);

	for(int i=1;i<=n;i++) {
		par[i]=i;
		sz[i]=1;
	}

	for(int i=0;i<m;i++) {
		inp(a);
		inp(b);
		inp(c);
		A[i]=make_pair(c,ii(a,b));
	}
	sort(A,A+m);
	ans=0;
	val=0;
	for(int i=m-1;i>=0;i--) {
		a=A[i].second.first;
		b=A[i].second.second;
		c=A[i].first;

		x=root(a);
		y=root(b);

		// cout<<x<<" "<<y<<endl;
		if(x==y) {
			// val+=((sz[x]*sz[x-1])/2)%mod;
			// val%=mod;
			ans+=(val*c)%mod;
			ans%=mod;
		}
		else {
			val+=(sz[x]*sz[y])%mod;
			val%=mod;
			ans+=(val*c)%mod;
			ans%=mod;
			union1(x,y);
		}
		// cout<<ans<<endl;
	}
	printf("%lld\n", ans);
	return 0;
}