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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int t,n,A[100][100],dp[100][100];
	double ans;
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				inp(A[i][j]);

		dp[0][0]=A[0][0];
		for(int i=1;i<n;i++) {
			dp[i][0]=dp[i-1][0]+A[i][0];
			dp[0][i]=dp[0][i-1]+A[0][i];
		}

		for(int i=1;i<n;i++) {
			for(int j=1;j<n;j++) {
				dp[i][j]=A[i][j]+min(dp[i-1][j],dp[i][j-1]);
			}
		}
		ans=dp[n-1][n-1];
		ans=ans/(double(2*n-1));
		printf("%.6f ", ans);

		for(int i=1;i<n;i++) {
			for(int j=1;j<n;j++) {
				dp[i][j]=A[i][j]+max(dp[i-1][j],dp[i][j-1]);
			}
		}
		ans=dp[n-1][n-1];
		ans=ans/(double(2*n-1));

		printf("%.6f\n", ans);
	}

	return 0;
}