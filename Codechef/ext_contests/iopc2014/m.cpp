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

int g[1000][1000];

int main() {
	int t,n,a,b,c,d,k,Q;

	inp(t);

	memset(g,-1,sizeof g);

	for(int idx=0;idx<t;idx++) {
		inp(n);
		inp(a);
		inp(b);
		inp(c);
		inp(d);
		inp(k);
		inp(Q);

		int dest=Q%k;

		queue<ii> q;
		queue<int> q1;

		if(n%k==dest) {
			printf("0\n");
			continue;
		}
		q.push(ii(n%k,n%d));
		g[n%k][n%d]=idx;
		q1.push(0);

		int ans=-1;

		while (!q.empty()){
			ii top=q.front();
			q.pop();

			int x=top.first;
			int y=top.second;
			int val=q1.front();
			q1.pop();


			int i,j;
			i=(x+a)%k;
			j=(y+a)%d;

			if(g[i][j]!=idx) {
				g[i][j]=idx;
				if(i==dest) {
					ans=val+1;
					break;
				}
				q.push(ii(i,j));
				q1.push(val+1);
			}

			i=(x-b)%k;
			j=(y-b)%d;

			i=(i+k)%k;
			j=(j+d)%d;

			if(g[i][j]!=idx) {
				g[i][j]=idx;
				if(i==dest) {
					ans=val+1;
					break;
				}
				q.push(ii(i,j));
				q1.push(val+1);
			}
			
			i=(x*c)%k;
			j=(y*c)%d;

			if(g[i][j]!=idx) {
				g[i][j]=idx;
				if(i==dest) {
					ans=val+1;
					break;
				}
				q.push(ii(i,j));
				q1.push(val+1);
			}

			i=y%k;
			j=y;

			if(g[i][j]!=idx) {
				g[i][j]=idx;
				if(i==dest) {
					ans=val+1;
					break;
				}
				q.push(ii(i,j));
				q1.push(val+1);
			}

		}
		printf("%d\n", ans);
	}

	return 0;
}