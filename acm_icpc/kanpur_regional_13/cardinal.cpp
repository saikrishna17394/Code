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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

bool check(int mask,int n) {
	int i;
	while(n) {
		i=n%10;
		if(mask&(1<<i))
			return false;
		n/=10;
	}
	return true;
}

int main() {
	int n,lim;
	lli A[100];
	int mask,num,bit;

	ii dp[100][1<<10];
	lim=1<<10;

	while(scanf("%d",&n)!=EOF) {

		for(int i=0;i<n;i++) {
			inp(A[i]);
		}

		// if(check(2))
		for(int i=0;i<lim;i++) {

			if(check(i,A[n-1])) {
				// cout<<i<<endl;
				dp[n-1][i].first=A[n-1];
				dp[n-1][i].second=1;
			}
			else {
				dp[n-1][i].first=0;
				dp[n-1][i].second=0;
			}

		}
		// cout<<dp[n-1][0].first<<" "<<dp[n-1][0].second<<endl;
		for(int i=n-2;i>=0;i--) {
			for(int j=0;j<lim;j++) {
				dp[i][j]=dp[i+1][j];
				if(check(j,A[i])) {
					mask=j;
					num=A[i];
					while(num) {
						bit=num%10;
						mask|=(1<<bit);
						num/=10;
					}

					// if(i==0 && j==0) {
					// 	cout<<A[i]<<endl;
					// 	cout<<mask<<endl;
					// 	cout<<dp[i+1][mask].first<<" "<<dp[i+1][mask].second<<endl;
					// }
					if(dp[i+1][mask].first+A[i]>dp[i][j].first) {
						dp[i][j].first=dp[i+1][mask].first+A[i];
						dp[i][j].second=dp[i+1][mask].second+1;
					}
					else if(dp[i+1][mask].first+A[i]==dp[i][j].first) {
						dp[i][j].second=max(dp[i][j].second,dp[i+1][mask].second+1);
					}
				}
			}

		}
		// cout<<dp[0][6].first<<" "<<dp[0][6].second<<endl;
		printf("%lld\n", dp[0][0].second);
	}

	return 0;
}