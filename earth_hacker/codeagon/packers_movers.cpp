#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int m,p,A[200],dp[201][20]={{0}};

int main() {

    scanf("%d %d",&m,&p);

    for(int i=0;i<p;i++)
        scanf("%d",&A[i]);

    // memset(dp,0,sizeof dp);

    for(int i=p-1;i>=0;i--) {
        dp[i][1]=dp[i+1][1]+A[i];
    }

    for(int j=2;j<=m;j++) {
        for(int i=0;i<p;i++) {
            dp[i][j]=dp[i][j-1];
            int val=0;
            for(int k=i;k<p;k++) {
                val+=A[k];
                dp[i][j]=min(dp[i][j],max(val,dp[k+1][j-1]));
            }
        }
    }

    printf("%d\n", dp[0][m]);
	return 0;
}