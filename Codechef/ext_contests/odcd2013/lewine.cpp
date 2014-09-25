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

int dp[50][5001];
int A[50],B[50],t,n,m;

int main() {

	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<m;i++) {
			inp(A[i]);
			inp(B[i]);
		}

		for(int j=0;j<=n;j++)
			dp[0][j]=(j/A[0])*B[0];

		for(int i=1;i<m;i++) {
			for(int j=0;j<=n;j++) {
				dp[i][j]=dp[i-1][j];
				if(j>=A[i])
					dp[i][j]=max(dp[i][j],B[i]+dp[i][j-A[i]]);
			}
		}
		printf("%d\n", dp[m-1][n]);
	}

	return 0;
}