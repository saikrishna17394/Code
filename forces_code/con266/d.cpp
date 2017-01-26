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

int n,h;
int A[2000];
lli dp[2000][2010];

lli solve(int i,int opens) {
	if(i==n) {
		if(opens==0) {
			// cout<<i<<" "<<opens<<" 1\n";
			return 1;
		}
		// cout<<i<<" "<<opens<<" 0\n";
		return 0;
	}
	lli & ret=dp[i][opens];
	if(ret!=-1)
		return ret;

	ret=0;
	
	if(A[i]+opens==h) {
		ret+=solve(i+1,opens);
		if(opens>0)
			ret+=(opens*solve(i+1,opens-1))%mod;
	}
	else if(A[i]+opens==(h-1)) {
		ret+=solve(i+1,opens+1);
		ret+=((opens+1)*solve(i+1,opens))%mod;
	}
	else 
		;
	ret%=mod;
	// cout<<i<<" "<<opens<<" "<<ret<<endl;
	return ret;
}

int main() {
	scanf("%d %d",&n,&h);

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	memset(dp,-1,sizeof dp);
	
	cout<<solve(0,0)<<endl;

	return 0;
}