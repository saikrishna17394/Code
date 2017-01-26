#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

int n,A[lim],dp[lim];
int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n;

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	dp[0]=1;
	int ans=1;

	for(int i=1;i<n;i++) {
		if(A[i]>=A[i-1])
			dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
		ans=max(ans,dp[i]);
	}

	printf("%d\n", ans);
	return 0;
}