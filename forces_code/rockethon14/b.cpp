#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 999999999
typedef long long int lli;
typedef pair<int,int> ii;


int A[1000],cnt,dp[1000];

int main() {
	string s;
	cin>>s;
	int n=s.length();

	int ans=0;

	dp[n-1]=1;
	ans=1;
	// cout<<n<<endl;
	for(int i=n-2;i>=0;i--) {
		dp[i]=1;
		for(int j=i+1;j<n;j++) {
			// cout<<i<<" "
			if(s[i]==s[j] && ((j-i)%2==1) ) {
				dp[i]=max(dp[i],1+dp[j]);
			// cout<<i<<" "<<j<<" "<<dp[i]<<endl;
			}
		}
		ans=max(ans,dp[i]);
	}

	printf("%d\n", ans);
	return 0;
}