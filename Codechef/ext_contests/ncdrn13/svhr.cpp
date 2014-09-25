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
int r,c,ans,vis[10][10];
string maze[10];
int dx[4]={+1,-1,0,0};
int dy[4]={0,0,+1,-1};
ii next[10][10],next1[10][10],p;

bool check(int i,int j) {
	if(i<0 || i>=r || j<0 || j>=c)
		return false;
	if(maze[i][j]!='#' && vis[i][j]==0)
		return true;
	return false;
}
bool dfs(int i,int j) {
	vis[i][j]=1;
	if(maze[i][j]=='E') {
		next[i][j]=ii(i,j);
		return true;
	}
	int i1,j1;
	for(int a=0;a<4;a++) {
		i1=i+dx[a];
		j1=j+dy[a];
		if(check(i1,j1) && dfs(i1,j1)) {
			next[i][j]=ii(i1,j1);
			return true;
		}
	}
	return false;
}

bool dfs1(int i,int j) {
	vis[i][j]=1;
	if(maze[i][j]=='E') {
		next1[i][j]=ii(i,j);
		return true;
	}
	int i1,j1;
	for(int a=0;a<4;a++) {
		i1=i+dx[a];
		j1=j+dy[a];
		if(check(i1,j1) && dfs1(i1,j1)) {
			next1[i][j]=ii(i1,j1);
			return true;
		}
	}
	return false;
}

int main() {
	inp(r);
	inp(c);

	for(int i=0;i<r;i++)
		cin>>maze[i];
	int h1,h2,v1,v2;

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(maze[i][j]=='H') {
				h1=i;
				h2=j;
				memset(vis,0,sizeof vis);
				bool sai=dfs(i,j);
			}
			else if(maze[i][j]=='V') {
				v1=i;
				v2=j;
				memset(vis,0,sizeof vis);
				bool sai=dfs1(i,j);
			}
			else
				;
		}
	}
	int ans=0;
	while(1) {
		// cout<<h1<<" "<<h2<<endl;
		// cout<<v1<<" "<<v2<<endl;
		if(h1==v1 && h2==v2) {
			printf("%d\n", ans);
			break;
		}
		if(maze[h1][h2]=='E') {
			printf("escape\n");
			break;
		}
		ans++;
		p=next[h1][h2];
		h1=p.first;
		h2=p.second;

		p=next1[v1][v2];
		p=next1[p.first][p.second];
		v1=p.first;
		v2=p.second;
	}
	return 0;
}