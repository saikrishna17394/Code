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

int n,a,b,k,dp[2][5001],A[5001];

int main() {
	cin>>n>>a>>b>>k;

	memset(dp,0,sizeof dp);

	dp[1][a]=1;
	k++;
	
	for(int i=2;i<=k;i++) {
		A[0]=0;
		A[1]=dp[(i-1)%2][1];
		for(int j=2;j<=n;j++)
			A[j]=(A[j-1]+dp[(i-1)%2][j])%mod;
		for(int j=1;j<=n;j++) {
			if(j==b)
				continue;
			if(j<b) {
				dp[i%2][j]=A[j-1];
				int l=j+1;
				int r=(j+b)/2;
				if(2*r==j+b)
					r--;
				if(l<=r) {
					dp[i%2][j]+=(A[r]-A[l-1])%mod;
				}
			}
			else {
				dp[i%2][j]=(A[n]-A[j])%mod;
				int r=j-1;
				int l=(b+j)/2;
				l++;

				if(l<=r) {
					dp[i%2][j]+=(A[r]-A[l-1])%mod;
				}
			}
			dp[i%2][j]%=mod;
			if(dp[i%2][j]<0)
				dp[i%2][j]+=mod;
		}
	}

	int ans=0;

	for(int j=1;j<=n;j++)
		ans=(ans+dp[k%2][j])%mod;
	printf("%d\n", ans);

	return 0;
}