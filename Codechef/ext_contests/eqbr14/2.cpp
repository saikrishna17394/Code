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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t;
int n,m;
int A[100][100];
int vis[100][100];
int ans;

void dfs(int i,int j) {
	vis[i][j]=1;
	ans=max(ans,i+j+1);


	if((j+1)<m && A[i][j]<A[i][j+1]) {
		if(vis[i][j+1]==0)
			dfs(i,j+1);
		if((i+1)<n && vis[i+1][j]==0)
			dfs(i+1,j);

	}
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				inp(A[i][j]);
			}
		}
		memset(vis,0,sizeof vis);

		ans=0;
		dfs(0,0);

		printf("%d\n", ans);
	}

	return 0;
}