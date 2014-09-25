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

lli dp[65][65];

lli solve(lli n,lli k) {

	lli num=n;
	vector<int> v;

	while(num) {
		// cnt++;
		v.push_back(num%2);
		num/=2;
	}

	lli ret=0,cnt=0;

	for(int i=v.size()-1;i>=0;i--) {
		if(v[i]==1) {
			if(i+cnt>=k && k-cnt>=0)
				ret+=dp[i][k-cnt];
			cnt++;
		}
	}

	if(cnt==k)
		ret++;
	return ret;

}

int main() {
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(int i=1;i<65;i++) {
		dp[i][0]=1;
		for(int j=1;j<=i;j++) {
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}

	lli l=1,r=1e18,m,k;

	cin>>m>>k;

	while(l<r) {

		lli mid=(l+r)/2;

		lli val=solve(2*mid,k);
		val-=solve(mid,k);

		// cout<<l<<" "<<r<<" "<<val<<endl;
		if(val<m) {
			l=mid+1;
		}
		else {
			r=mid;
		}
	}

	cout<<l<<endl;

	return 0;
}