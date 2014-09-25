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

int m,n;
int A[20],B[20];

lli dp[20][101];

int main() {
	while(1) {
		inp(m);
		inp(n);

		if(m==0 && n==0)
			break;

		for(int i=0;i<m;i++) {
			inp(B[i]);
			inp(A[i]);
			A[i]-=B[i];
			n-=B[i];
		}
		if(n<0) {
			printf("0\n");
			continue;
		}
		if(n==0) {
			printf("1\n");
			continue;
		}
		
		// cout<<n<<" "<<A[0]<<endl;
		for(int j=0;j<=min(n,A[0]);j++)
			dp[0][j]=1;
		for(int j=A[0]+1;j<=n;j++)
			dp[0][j]=0;

		for(int i=1;i<m;i++) {
			for(int j=0;j<=n;j++) {
				dp[i][j]=0;

				for(int k=0;k<=min(j,A[i]);k++) {
					dp[i][j]+=dp[i-1][j-k];
				}
				// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}
		printf("%lld\n", dp[m-1][n]);
	}
	return 0;
}