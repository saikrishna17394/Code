#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,m;
int A[401][401]={0};
int vis[401]={0};

int edge=0;

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n>>m;

	int val=n*(n-1);
	val/=2;

	if(m==0 || m==val) {
		printf("-1\n");
		return 0;
	}

	while(m--) {
		int u,v;
		cin>>u>>v;
		A[u][v]=1;
		A[v][u]=1;
	}

	if(A[1][n]==0)
		edge=1;

	queue<pair<int,int> > q;

	q.push(make_pair(0,1));

	vis[1]=1;

	while(!q.empty()) {
		ii ver=q.front();
		q.pop();

		if(ver.second==n) {
			printf("%d\n", ver.first);
			return 0;
		}
		for(int j=1;j<=n;j++) {
			if(A[ver.second][j]==edge && vis[j]==0) {
				vis[j]=1;
				q.push(ii(ver.first+1,j));
			}
		}

	}

	printf("-1\n");
	return 0;
}