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

int main() {
	int t,n,g[201][201],k,a,ans,par[201],ver,vis[201];
	list<int> l[201];
	queue<int> q;
	inp(t);

	while(t--) {
		inp(n);
		memset(g,0,sizeof g);

		for(int i=1;i<=n;i++)
			l[i].clear();

		for(int i=1;i<n;i++) {
			inp(k);
			while(k--) {
				inp(a);
				if(i==1 || a==n)
					g[i][a]=1;
				else
					g[i][a]=n-2;
				l[i].push_back(a);
				l[a].push_back(i);
			}
		}

		ans=0;
		while(1) {
			memset(vis,0,sizeof vis);

			while(!q.empty())
				q.pop();
			q.push(1);
			vis[1]=1;

			while(!q.empty()) {
				ver=q.front();
				q.pop();

				for(list<int>::iterator it=l[ver].begin();it!=l[ver].end();it++) {
					if(vis[*it]==0 && g[ver][*it]) {
						vis[*it]=1;
						par[*it]=ver;
						if(*it==n) {
							ver=n;
							break;
						}
						q.push(*it);
					}
				}
				if(ver==n)
					break;

			}

			if(ver==n) {
				ans++;
				int ind=n;
				// cout<<n<<" ";
				while(ind>1) {
					g[par[ind]][ind]--;
					g[ind][par[ind]]++;
					ind=par[ind];
					// cout<<ind<<" ";
				}
				// cout<<endl;
			}
			else
				break;
		}
		printf("%d\n", ans);
	}

	return 0;
}