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

int m,s;
int dp[200];

bool solve(int len, int sum) {
	// cout<<len<<" "<<sum<<endl;
	if(len==0) {
		if(sum==0)
			return true;
		return false;
	}
	if(sum>9*len || sum<0)
		return false;

	for(int i=0;i<10;i++) {
		if(solve(len-1,sum-i)) {
			dp[m-len]=i;
			return true;
		}
	}
	return false;
}

bool solve1(int len, int sum) {
	if(len==0) {
		if(sum==0)
			return true;
		return false;
	}
	if(sum>9*len || sum<0)
		return false;

	for(int i=9;i>=0;i--) {
		if(solve1(len-1,sum-i)) {
			dp[m-len]=i;
			return true;
		}
	}
	return false;
}

int main() {
	cin>>m>>s;

	if(s==0 && m==1) {
		printf("0 0\n");
		return 0;
	}
	if(s==0 || s>9*m) {
		printf("-1 -1\n");
		return 0;
	}


	for(int i=1;i<10;i++) {
		// cout<<i<<"wht\n";
		if(solve(m-1,s-i)) {
			printf("%d",i );
			for(int j=1;j<m;j++)
				printf("%d",dp[j] );
			printf(" ");
			break;
		}
	}


	for(int i=9;i>0;i--) {
		if(solve1(m-1,s-i)) {
			printf("%d",i );
			for(int j=1;j<m;j++)
				printf("%d",dp[j] );
			printf("\n");
			break;
		}
	}
	return 0;
}
