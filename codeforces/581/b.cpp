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

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
	}	

	dp[n-1]=A[n-1];

	for(int i=n-2;i>=0;i--)
		dp[i]=max(A[i],dp[i+1]);

	for(int i=0;i<(n-1);i++)
		printf("%d ", max(dp[i+1]+1-A[i],0));
	printf("0\n");
	return 0;
}