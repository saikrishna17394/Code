#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define lim 100
typedef long long int lli;
typedef pair<int,int> ii;

lli p[lim],e[lim],inf;
lli dp[lim][lim+2][lim+2];
int n,k;

lli fun(int idx,int r,int wins) {
	if(idx==n && r==1)
		return 0;
	lli& ret=dp[idx][r];
	if(ret!=-1)
		return ret;

	ret=inf;

	// for(int i=0;i<(n-idx-1))



}

int main() {
	inf=(lli)1e18;
	scanf("%d %d",&n,&k);

	for(int i=0;i<n;i++) {
		cin>>p[i];
		cin>>e[i];
	}

	memset(dp,-1,sizeof dp);

	cout<<fun(0,k,0)<<endl;

	return 0;
}