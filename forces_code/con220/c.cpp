#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

map<char,int> M;
string s[1000];
int n,m,vis[1000][1000];

int dfs(int i,int j) {

}

int main() {
	M['D']='I';
	M['I']='M';
	M['M']='A';
	M['A']='D';
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];

	memset(vis,-1,sizeof vis);
	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(s[i][j]=='D') {
				ans=max(ans,dfs(i,j));
			}
		}
	}

	return 0;
}