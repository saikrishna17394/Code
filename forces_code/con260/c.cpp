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

lli n,A[100000],cnt,ans;

lli B[100000],dp[100000];

void solve() {
	dp[cnt-1]=B[cnt-1];
	lli ret=B[cnt-1];

	for(int j=cnt-2;j>=0;j--) {
		dp[j]=max(dp[j+1],B[j]);

		if((j+2)<cnt)
			dp[j]=max(dp[j],B[j]+dp[j+2]);

		ret=max(ret,dp[j]);
	}
	ans+=ret;
}


int main() {
	scanf("%lld",&n);

	for(int i=0;i<n;i++)
		scanf("%lld",&A[i]);

	sort(A,A+n);

	ans=0;

	cnt=0;

	B[cnt++]=A[0];

	for(int i=1;i<n;i++) {
		if(A[i]==A[i-1])
			B[cnt-1]+=A[i];
		else if(A[i]==A[i-1]+1)
			B[cnt++]=A[i];
		else {
			solve();
			cnt=0;
			B[cnt++]=A[i];
		}
	}

	solve();

	printf("%lld\n", ans);

	return 0;
	
}