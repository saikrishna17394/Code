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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int t,m,n,A[50][50];

int g[102][102],vis[102],par[102];

int main() {
	inp(t);

	while(t--) {
		inp(m);
		inp(n);

		memset(g,0,sizeof g);
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				inp(A[i][j]);
				g[i+1][m+j+1]=1;
			}
		}

		for(int i=0;i<m;i++)
			g[0][i]=1;

		for(int i=m+1;i<=m+n;i++)
			g[i][m+n+1]=1;

		int ans=0;

		while(1) {
			queue<int> q;
			memset(vis,0,sizeof vis);

			q.push(0);
			vis[0]=1;
			int ver;
			bool ok=true;
			while(!q.empty()) {
				ver=q.front();
				q.pop();

				if(g[ver][m+n+1]) {
					par[m+n+1]=ver;
					ok=false;
					break;
				}

				for(int i=1;i<=m+n;i++) {
					if(g[ver][i] && vis[i]==0) {
						vis[i]=1;
						par[i]=ver;
						q.push(i);
					}
				}
			}
			if(ok)
				break;
			ans++;
			ver=m+n+1;

			while(ver) {
				g[par[ver]][ver]^=1;
				g[ver][par[ver]]^=1;
				ver=par[ver];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}