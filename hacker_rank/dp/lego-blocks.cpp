#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	long long int dp[1001][1001]={0},A[1001]={0};

	dp[1][1]=1;
	dp[2][1]=1;
	dp[3][1]=1;
	dp[4][1]=1;

	A[0]=1;
	A[1]=1;
	A[2]=2;
	A[3]=4;
	for(int i=4;i<1001;i++) {
		A[i]=(A[i-4]+A[i-3]+A[i-2]+A[i-1])%mod;
	}
	cout<<A[4]<<endl;
	for(int j=2;j<1001;j++) {
		dp[1][j]=1;
		for(int i=2;i<1001;i++) {
			dp[i][j]=(A[i]*dp[i][j-1])%mod;
		}
	}
	return 0;
}