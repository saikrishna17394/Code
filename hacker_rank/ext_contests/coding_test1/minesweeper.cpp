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
#define ii pair<long long int,long long int>

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
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={-1,0,1,-1,0,1,1,-1};

int t,n,vis[300][300],A[300][300];
string s[300];

int cnt(int i,int j) {
	int ret=0;
	for(int a=0;a<8;a++) {
		int x=i+dx[a],y=j+dy[a];

		if(x<0 || y<0 || x>=n || y>=n)
			continue;
		if(s[x][y]=='*')
			ret++;
	}
	return ret;
}

void dfs(int i,int j) {
	vis[i][j]=1;
	if(A[i][j]>0)
		return ;

	for(int a=0;a<8;a++) {
		int x=i+dx[a],y=j+dy[a];

		if(x<0 || y<0 || x>=n || y>=n)
			continue;
		if(A[x][y]>=0 && vis[x][y]==0)
			dfs(x,y);
	}
}
int main() {
	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		for(int i=0;i<n;i++)
			cin>>s[i];

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(s[i][j]=='*')
					A[i][j]=-1;
				else
					A[i][j]=cnt(i,j);
			}
		}
		
		memset(vis,0,sizeof vis);

		int ans=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(vis[i][j]==0 && A[i][j]==0) {
					dfs(i,j);
					ans++;
				}
			}
		}

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(vis[i][j]==0 && A[i][j]>0) {
					ans++;
				}
			}
		}

		printf("Case #%d: %d\n",a,ans );
	}

	return 0;
}