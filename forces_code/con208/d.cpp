#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;

int dp[3000][3000][2];
int n,A[3000][3];

int ans(int i,int j,int x) {
	if(dp[i][j][x]!=-1)
		return dp[i][j][x];

	if(i==j) {
		return A[i][x];
	}
	int val=0;
	if(x==0) {
		val=A[i][0]+ans(i+1,j,1);
		val=max(val,A[i][1]+ans(i+1,j,0));
	}
	else {
		val=A[i][1]+ans(i+1,j,1);
		val=max(val,A[i][2]+ans(i+1,j,0));
	}
	dp[i][j][x]=val;
	return val;
}
int main() {
	memset(dp,-1,sizeof dp);

	scanf("%d",&n);

	for(int j=0;j<3;j++) {
		for(int i=0;i<n;i++)
			scanf("%d",&A[i][j]);
	}

	printf("%d\n", ans(0,n-1,0));

	return 0;
}