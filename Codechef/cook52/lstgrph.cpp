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

int n,m,k,u,v,y;
vector<ii> g[200001];
int vis[200001];

queue<int> q;
int lab[200001];

int main() {
	inp(n);
	inp(m);
	inp(k);

	while(m--) {
		inp(u);
		inp(v);
		inp(y);
		g[u].push_back(ii(v,y));
		g[v].push_back(ii(u,y));
	}

	memset(vis,0,sizeof vis);

	int last=-1;

	for(int i=1;i<=n;i++) {
		if(vis[i]==0) {
			last=i;

			
			int ver=i;
			q.push(i);
			lab[i]=0;
			vis[i]=1;

			while(!q.empty()) {
				ver=q.front();
				q.pop();

				for(int j=0;j<g[ver].size();j++) {
					int v=g[ver][j].first,y=g[ver][j].second;
					if(vis[v]==0) {
						vis[v]=1;
						lab[v]=lab[ver]^y;
						q.push(v);
					}
					else {
						if(lab[v]!=(lab[ver]^y)) {
							printf("-1\n");
							return 0;
						}
					}
				}
			}
		}
	}


	memset(vis,0,sizeof vis);

	int ver=last;
	q.push(last);
	lab[last]=k-1;
	vis[last]=1;

	while(!q.empty()) {
		ver=q.front();
		q.pop();

		for(int j=0;j<g[ver].size();j++) {
			int v=g[ver][j].first,y=g[ver][j].second;
			if(vis[v]==0) {
				vis[v]=1;
				lab[v]=lab[ver]^y;
				q.push(v);
			}
			else {
				if(lab[v]!=(lab[ver]^y)) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}


	for(int i=1;i<=n;i++)
		printf("%d ", lab[i]);
	printf("\n");
	return 0;
}