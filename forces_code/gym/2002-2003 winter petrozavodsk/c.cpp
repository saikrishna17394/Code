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

int n,A[500001];
vector<int> g[500001];

int dp[500001][2],soln[500001][2];

int solve(int i,int x) {
	if(dp[i][x]!=-1)
		return dp[i][x];

	int &ret=dp[i][x];

	soln[i][x]=0;

	if(x==1) {
		ret=1;
		for(int j=0;j<g[i].size();j++) {
			ret+=solve(g[i][j],0);
		}
	}
	else {
		ret=0;
		int val=0;
		for(int j=0;j<g[i].size();j++) {
			val+=solve(g[i][j],0);
		}
		ret=max(ret,val);

		for(int j=0;j<g[i].size();j++) {
			int num=val-solve(g[i][j],0)+solve(g[i][j],1);

			if(num>ret) {
				ret=num;
				soln[i][x]=g[i][j];
			}
		}
	}
	// cout<<i<<" "<<x<<" "<<dp[i][x]<<endl;
	return ret;

}

vector<int> v;

void print(int i,int x) {
	if(x==1) {
		v.push_back(i);

		for(int j=0;j<g[i].size();j++)
			print(g[i][j],0);
	}
	else {
		for(int j=0;j<g[i].size();j++) {
			if(soln[i][x]==g[i][j])
				print(g[i][j],1);
			else
				print(g[i][j],0);
		}
	}
}

int main() {
	freopen("grant.in", "r", stdin);
	freopen("grant.out", "w", stdout);
	cin>>n;

	A[1]=1;

	for(int i=2;i<=n;i++) {
		cin>>A[i];
		g[A[i]].push_back(i);
	}

	memset(dp,-1,sizeof dp);

	int ans;

	ans=max(solve(1,0),solve(1,1)-1);

	ans*=1000;

	cout<<ans<<endl;

	if(solve(1,0)>=(solve(1,1)-1))
		print(1,0);
	else
		print(1,1);

	sort(v.begin(),v.end());

	for(int i=0;i<v.size();i++) {
		if(v[i]==1)
			;
		else
			cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}