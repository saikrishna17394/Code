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

int n,A[100],vis[100][1024];
string g[100];
queue<ii> q;

int main() {
	inp(n);

	for(int i=0;i<n;i++) {
		inp(A[i]);
	}

	memset(vis,0,sizeof vis);

	int ans=A[0];

	for(int i=0;i<n;i++)
		cin>>g[i];

	// cout<<"yo\n";
	int a=0,b=A[0];

	q.push(ii(a,b));

	vis[a][b]=1;

	while(!q.empty()) {
		ii ver=q.front();
		q.pop();
		// cout<<ver.first<<" "<<ver.second<<endl;
		// cout<<"man\n"

		int val=ver.second;

		for(int i=0;i<n;i++) {
			if(g[ver.first][i]=='Y' && vis[i][val|A[i]]==0) {
				vis[i][val|A[i]]=1;
				q.push(ii(i,val|A[i]));
				ans=max(ans,val|A[i]);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}