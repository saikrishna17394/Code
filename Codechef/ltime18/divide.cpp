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

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli power(lli n,lli k) {
	lli ret=1;

	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}


lli t,n;
lli g[1000][1000];
lli A[1000];
int vis[1000];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(lli i=0;i<n;i++)
			inp(A[i]);

		for(lli i=0;i<n;i++) {
			for(lli j=i+1;j<n;j++) {
				g[i][j]=min(power(A[i],A[j]),power(A[j],A[i]));
				g[j][i]=g[i][j];
				// cout<<g[i][j]<<" ";
			}
			// printf("\n");
			g[i][i]=-1;
		}

		// for(int i=0;i<n;i++) {
		// 	for(int j=0;j<n;j++)
		// 		printf("%lld ",g[i][j] );
		// 	printf("\n");
		// }

		lli l=0,r=mod;

		while(l<r) {
			// cout<<l<<" "<<r<<endl;
			lli m=(l+r)/2;

			for(int i=0;i<n;i++)
				vis[i]=-1;

			queue<ii> q;
			while(!q.empty())
				q.pop();
			

			bool ok=true;

			for(int i=0;i<n;i++) {
				if(vis[i]!=-1)
					continue;
				q.push(ii(i,0));
				vis[i]=0;

				while(!q.empty()) {
					ii p=q.front();
					// cout<<p.first<<" : "<<p.second<<endl;
					q.pop();

					for(int j=0;j<n;j++) {
						if(j==p.first)
							continue;

						if(vis[j]==-1 && g[p.first][j]>m) {
							vis[j]=1^p.second;
							q.push(ii(j,vis[j]));
						}
						else if(g[p.first][j]>m && vis[j]==p.second) {
							ok=false;
							break;
						}
						else
							;
					}
					if(!ok)
						break;
				}
			}

			// cout<<m<<" wht "<<ok<<endl;
			if(ok)
				r=m;
			else
				l=m+1;
		}
		printf("%lld\n", l);
	}


	return 0;
}