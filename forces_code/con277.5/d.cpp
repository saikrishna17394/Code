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
#define lim 10000000

using namespace std;

int n,m;
vector<int> g[3001];
int a,b;

int B[3001],vis[3001];

lli ncr(lli num) {
	lli ret=num*(num-1);
	return ret/2;
}

int main() {
	cin>>n>>m;

	while(m--) {
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
	}

	lli ans=0;

	for(int i=1;i<=n;i++) {
		memset(B,0,sizeof B);

		for(int j=0;j<g[i].size();j++) {
			for(int k=0;k<g[g[i][j]].size();k++) {
				B[g[g[i][j]][k]]++;
			}
		}

		for(int j=1;j<=n;j++) {
			if(i==j)
				continue;
			ans+=ncr((lli)B[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}