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
#define ii pair<long long int,int>

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

int main() {
	int t,n,hash[1001],g[1001][1001],k,m,x,y,a,b,cost;

	lli d[1001],ans;
	set<ii> s;

	inp(t);

	int A[1001][1001],B[1001][1001];

	while(t--) {
		inp(n);
		inp(k);

		s.clear();
		for(int i=1;i<=n;i++) {
			scanf("%lld",&d[i]);
		}

		inp(m);
		inp(x);
		inp(y);
		for(int i=1;i<=n;i++) {
			if(i==x || i==y)
				continue;
			s.insert(ii(d[i],i));
		}
		int ind=1;
		for(set<ii>::iterator it=s.begin();it!=s.end();it++) {
			hash[ind++]=it->second;
		}

		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==j)
					g[i][j]=0;
				else
					g[i][j]=inf;
			}
		}

		while(m--) {
			inp(a);
			inp(b);
			inp(cost);
			g[a][b]=cost;
			g[b][a]=cost;
		}
		if(n==1) {
			printf("%lld\n", d[1]);
			continue;
		}
		ans=max(d[x],d[y]);

		if(g[x][y]<=k) {
			printf("%lld\n", ans);
			continue;
		}

		for(int i=1;i<ind;i++) {
			A[i][0]=g[x][hash[i]];
			B[i][0]=g[hash[i]][y];
		}
		A[ind][0]=g[x][y];
		B[0][0]=g[x][y];

		bool krish=false;

		for(int a=1;a<ind;a++) {
			ans=max(ans,d[hash[ind]]);

			A[ind][a]=min(A[ind][a-1],A[a][a-1]+B[a][a-1]);
			B[0][a]=A[ind][a];

			if(A[ind][a]<=k) {
				printf("%lld\n", ans);
				krish=true;
				break;
			}

			for(int i=1;i<=a;i++) {
				A[i][a]=min(A[i][a-1],A[a][a-1])
			}
		}

		if(krish)
			continue;
		printf("-1\n");
	}

	return 0;
}