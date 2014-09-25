#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <list>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int t,n,m,k,a,b,ans,vis[3000],dis[3000],low[3000],par[3000],tim;
int A[3000][3000],cnt[3000];

void dfs(int i) {
	
	dis[i]=++tim;
	low[i]=tim;
	vis[i]=1;

	bool mark=false;
	for(int j=0;j<cnt[i];j++) {
		if(vis[A[i][j]]==0) {
			par[A[i][j]]=i;
			dfs(A[i][j]);

			if(low[A[i][j]]>=dis[i])
				mark=true;
			else
				low[i]=min(low[i],low[A[i][j]]);

		}
		else if(par[A[i][j]]!=i) {
			low[i]=min(low[i],dis[A[i][j]]);
		}
		else
			;
	}

	if(mark==true) {
		ans++;
	}

}

int main() {

	inp(t);
	while(t--) {
		inp(n);
		inp(m);
		inp(k);

		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);

		ans=0;


		while(m--) {
			inp(a);
			inp(b);
			A[a][cnt[a]++]=b;
			A[b][cnt[b]++]=a;
		}


		int val=0;
		tim=1;
		
		dis[0]=tim;
		vis[0]=1;
		par[0]=-1;

		for(int i=0;i<cnt[0];i++) {
			if(vis[A[0][i]]==0) {
				par[A[0][i]]=0;
				dfs(A[0][i]);
				val++;
			}
		}
		
		if(val>1) {
			ans++;
		}

		printf("%d\n",ans*k);
	}
	return 0;
}