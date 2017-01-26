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
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int dp[1000][1000],A[1000][1000];
int m,n,p;


int main() {

	cin>>m>>n>>p;

	memset(A,0,sizeof A);
	memset(dp,0,sizeof dp);

	for(int i=0;i<p;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		A[a][b]=1;
	}

	if(A[0][0]==0)
		dp[0][0]=1;

	for(int i=1;i<m;i++) {
		if(A[i][0]==0)
			dp[i][0]=dp[i-1][0];
	}

	for(int j=1;j<n;j++) {
		if(A[0][j]==0)
			dp[0][j]=dp[0][j-1];
	}

	for(int i=1;i<m;i++) {
		for(int j=1;j<n;j++) {
			if(A[i][j]==1)
				continue;
			if(A[i][j-1]==0)
				dp[i][j]+=dp[i][j-1];
			if(A[i-1][j]==0)
				dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
		}
	}

	cout<<dp[m-1][n-1]<<endl;


	return 0;
}