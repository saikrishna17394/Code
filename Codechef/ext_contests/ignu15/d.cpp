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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,m;
string s[100];

vector<int> v[30000];
int match[10000],vis[10000];
int A[100][100];

bool dfs(int u) {
	// printf("%d\n", u);

	for(int j=0;j<v[u].size();j++) {
		int nxt=v[u][j];

		if(vis[nxt]==1)
			continue;
		vis[nxt]=1;

		if(match[nxt]==-1 || dfs(match[nxt])) {
			match[nxt]=u;
			return true;
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

		int idx=0;

		for(int i=0;i<30000;i++)
			v[i].clear();

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(s[i][j]=='H') {
					continue;
				}
				if(j==0 || s[i][j-1]=='H') {
					idx++;
					A[i][j]=idx;
					// v[idx].push_back(i*m+j);
				}
				else {
					A[i][j]=idx;
					// v[idx].push_back(i*m+j);
				}
			}
		}

		idx=0;
		for(int j=0;j<m;j++) {
			for(int i=0;i<n;i++) {
				if(s[i][j]=='H')
					continue;

				if(i==0 || s[i-1][j]=='H') {
					idx++;
					v[idx].push_back(A[i][j]);
				}
				else {
					v[idx].push_back(A[i][j]);
				}
			}
		}

		// printf("bro\n");

		memset(match,-1,sizeof match);

		int ans=0;
		
		for(int i=0;i<(idx+10);i++) {
			if(v[i].size()==0)
				continue;
			// printf("%d : ", i);
			// for(int j=0;j<v[i].size();j++)
			// 	printf("%d ",v[i][j] );
			// printf("\n");
			memset(vis,0,sizeof vis);

			if(dfs(i))
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}