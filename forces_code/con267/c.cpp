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

// #define imax numeric_limits<int>::max()
// #define imin numeric_limits<int>::min()
// #define lmax numeric_limits<ll>::max()
// #define lmin numeric_limits<ll>::min()


using namespace std;
lli dp[5001][5001];
lli n,m,k,A[5000],sum[5000]={0};

lli solve(int i,int j) {
	if(j==0 || i>=n)
		return 0;

	lli &ret=dp[i][j];

	if(ret!=-1)
		return ret;

	ret=0;

	// lli sum=0;
	// for(int a=i;a<(i+m);a++)
	// 	sum+=A[a];

	ret=sum[i]+solve(i+m,j-1);

	if((i+1+m)<=n)
		ret=max(ret,solve(i+1,j));

	return ret;
}

int main() {
	cin>>n>>m>>k;

	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<m;i++)
		sum[0]+=A[i];
	for(int i=1;(i+m)<=n;i++) {
		sum[i]=sum[i-1]+A[i+m-1]-A[i-1];
	}

	memset(dp,-1,sizeof dp);

	printf("%lld\n", solve(0,(int)k));


	return 0;
}