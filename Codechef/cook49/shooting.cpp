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
int t,m,n,g[16],g1[48][2],g2[48][2500][2],g3[2500];
string s[50];

int vis[16],vis1[48],vis2[2500],cnt;
bool dfs1(int i);
bool dfs2(int i);
bool dfs3(int i);

bool dfs() {
	for(int i=0;i<cnt;i++) {
		if(g[i]==1 && vis[i]==0) {
			vis[i]=1;
			if(dfs1(i)) {
				g[i]=0;
				return true;
			}
		}
	}
	return false;
}

bool dfs1(int i) {
	for(int j=0;j<3;j++) {
		if(g1[i*3+j][0]==1 && vis1[i*3+j]==0) {
			vis1[i*3+j]=1;
			if(dfs2(i*3+j)) {
				g1[i*3+j][0]=0;
				g1[i*3+j][1]=1;
				return true;
			}
		}
	}
	return false;
}

bool dfs2(int i) {
	for(int j=0;j<n*m;j++) {
		if(g2[i][j][0]==1 && vis2[j]==0) {
			vis2[j]=1;
			if(dfs3(j)) {
				g2[i][j][0]=0;
				g2[i][j][1]=1;
				return true;
			}
		}
	}

	if(g1[i][1]==1 && vis[i/3]==0) {
		vis[i/3]=1;
		if(dfs1(i/3)) {
			g1[i][1]=0;
			g1[i][0]=1;
			return true;
		}
	}
	return false;
}

bool dfs3(int i) {
	if(g3[i]==1) {
		g3[i]=0;
		return true;
	}
	for(int j=0;j<3*cnt;j++) {
		if(g2[j][i][1]==1 && vis1[j]==0) {
			vis1[j]=1;
			if(dfs2(j)) {
				g2[j][i][1]=0;
				g2[j][i][0]=1;
				return true;
			}
		}
	}
	return false;
}
int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<n;i++)
			cin>>s[i];

		memset(g,0,sizeof g);
		memset(g1,0,sizeof g1);
		memset(g2,0,sizeof g2);
		memset(g3,0,sizeof g3);

		cnt=0;
		int tot=0;

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(s[i][j]=='L') {
					g[cnt]=1;
					for(int k=0;k<j;k++)
						if(s[i][k]=='E')
							g2[cnt*3][i*n+k][0]=1;

					for(int k=j+1;k<m;k++)
						if(s[i][k]=='E')
							g2[cnt*3+1][i*n+k][0]=1;

					for(int k=0;k<i;k++)
						if(s[k][j]=='E')
							g2[cnt*3+2][k*n+j][0]=1;
					g1[cnt*3][0]=1;
					g1[cnt*3+1][0]=1;
					g1[cnt*3+2][0]=1;
					cnt++;
				}
				if(s[i][j]=='E') {
					g3[i*n+j]=1;
					tot++;
				}
			}
		}

		int ans=0;
		while(1) {
			cout<<"   asdf "<<ans<<endl;
			memset(vis,0,sizeof vis);
			memset(vis1,0,sizeof vis1);
			memset(vis2,0,sizeof vis2);

			if(dfs())
				ans++;
			else
				break;
		}

		if(ans==tot)
			printf("Possible\n");
		else
			printf("Impossible\n");

	}


	return 0;
}