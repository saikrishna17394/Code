#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define lli long long int
#define ii pair<int,int>
#define mp make_pair
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

int t,n,A[1000][1000],vis[1000][1000];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool check(int x,int y) {
	if(x<0 || y<0 || x>=n || y>=n || vis[x][y]==1)
		return false;
	return true;
}

int main() {
	// freopen("inp","r",stdin);
	// freopen("A-small-practice.in", "r", stdin);	
	// freopen("A-large-practice.in", "r", stdin);

	// freopen("A-small-attempt0.in", "r", stdin);	
	freopen("A-large.in", "r", stdin);	

	freopen("out.txt", "w", stdout);

	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) {
				inp(A[i][j]);
				vis[i][j]=0;
			}


		int ans=inf,sm=0;

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				// cout<<i<<" "<<j<<" "<<endl;
				if(vis[i][j]==1)
					continue;
				int idx=A[i][j];
				int val=0;

				queue<ii> q;
				q.push(ii(i,j));
				vis[i][j]=1;

				while(!q.empty()) {
					ii v=q.front();
					q.pop();
					val++;
					idx=min(idx,A[v.first][v.second]);
					// printf("%d %d\n", v.first,v.second);
					// printf("%d %d\n", A[v.first][v.second],val);
					// printf("\n");
					for(int a=0;a<4;a++) {
						int x=v.first+dx[a];
						int y=v.second+dy[a];

						if(check(x,y) && abs(A[v.first][v.second]-A[x][y])==1) {
							vis[x][y]=1;
							q.push(ii(x,y));
						}
					}
				}
				// printf("\n");
				if(val>sm) {
					sm=val;
					ans=idx;
				}
				else if(val==sm) {
					ans=min(ans,idx);
				}
				else
					;

			}
		}


		printf("Case #%d: %d %d\n",a, ans,sm);

	}


	return 0;
}