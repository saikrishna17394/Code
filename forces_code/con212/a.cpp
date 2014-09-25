#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;

int dx[4]={+2,+2,-2,-2};
int dy[4]={+2,-2,+2,-2};
string chess[8];
int A[8][8][2],vis[8][8],val;
bool ok;

bool check(int i,int j) {
	if(i<0 || i>7)
		return false;
	if(j<0 || j>7)
		return false;
	if(vis[i][j]==1)
		return false;
	return true;
}

void dfs(int i,int j) {
	vis[i][j]=1;
	if(chess[i][j]!='#')
		A[i][j]++;

	for(int k=0;k<4;k++) {
		if(check(i+dx[k],j+dy[k]))
			dfs(i+dx[k],j+dy[k]);
	}
}
int main() {
	int t;
	cin>>t;
	queue<ii> q;
	ii p;

	while(t--) {
		for(int i=0;i<8;i++)
			cin>>chess[i];
		memset(A,-1,sizeof A);

		val=0;

		for(int i=0;i<8;i++) {
			for(int j=0;j<8;j++) {
				if(chess[i][j]=='K') {
					memset(vis,0,sizeof vis);
					q.push(ii(i,j));
					
					vis[i][j]=1;
					A[i][j][val]=0;

					while(!q.empty()) {
						p=q.front();
						q.pop();

						for(int k=0;k<4;k++) {
							int x=p.first+dx[k];
							int y=p.second+dy[k];
							if(check(x,y)) {
								vis[x][y]=1;
								A[x][y][val]=1+A[p.first][p.second][val];
								q.push(ii(x,y));
							}
						}
					}
					val++;
				}
			}
		}
		ok=false;

		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				if(A[i][j]==2) {
					// cout<<i<<" "<<j<<endl;
					ok=true;
				}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}