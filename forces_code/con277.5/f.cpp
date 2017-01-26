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

#define inf 999999999
#define lim 10000000

using namespace std;

lli dp[501][501],n,m,mod;
string A[500];
int B[500]={0};

lli solve(int x,int y) {
	lli& ret=dp[x][y];
	if(ret!=-1)
		return ret;
	if(x==0 && y==0) {
		ret=1;
		return ret%mod;
	}

	ret=0;

	lli val;
	if(y>0) {
		val=(lli)(y*(y-1));
		val/=2;
		ret+=(val*solve(x,y-2))%mod;
	}
	if(x>0 && y>0) {
		val=(lli)(x*y);
		ret+=(val*solve(x-1,y))%mod;
	}
	if(x>1) {
		val=(lli)(x*(x-1));
		val/=2;
		ret+=(val*solve(x-2,y+2))%mod;
	}
	ret%=mod;
	return ret;
}

int main() {
	memset(dp,-1,sizeof dp); 	
	cin.sync_with_stdio(false);

	cin>>n>>m>>mod;
	for(int i=0;i<m;i++) {
		
		cin>>A[i];
		for(int j=0;j<n;j++) {
			if(A[i][j]=='1') {
				B[j]++;
			}
		}
	}

	int x=0,y=0;
	for(int j=0;j<n;j++) {
		if(B[j]==0)
			x++;
		else if(B[j]==1)
			y++;
		else
			;
	}
	// cout<<x<<" "<<y<<endl;
	if((2*x+y)!=2*(n-m)) {
		printf("0\n");
		// cout<<"what\n"<<endl;
		return 0;
	}

	cout<<solve(x,y)<<endl;

	return 0;
}