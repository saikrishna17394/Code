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

int t,n,c;
int A[100];
int dp[100][10001];


int main() {
	inp(t);

	while(t--) {

		memset(dp,0,sizeof dp);
		
		printf("YES\n");

		for(int i=0;i<idx;i++)
			printf("%d ",A[i] );
		printf("\n");

		for(int i=idx;i<n;i++)
			printf("%d ",A[i] );
		printf("\n");
	}


	return 0;
}