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

char s[5010][5010];
int dp[5000][5000],n,m,ans,A[5000];

int main() {
	// cin>>n>>m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);

	for(int i=0;i<n;i++)
		dp[i][m-1]=s[i][m-1]-'0';

	for(int i=0;i<n;i++) {
		for(int j=m-2;j>=0;j--) {
			if(s[i][j]=='0')
				dp[i][j]=0;
			else
				dp[i][j]=1+dp[i][j+1];
		}
	}
	ans=0;

	for(int j=0;j<m;j++) {
		for(int i=0;i<n;i++) {
			A[i]=dp[i][j];
		}
		sort(A,A+n);

		for(int i=n-1;i>=0;i--) {
			ans=max(ans,A[i]*(n-i));
		}
	}
	// cout<<ans<<endl;
	printf("%d\n", ans);
	return 0;
}