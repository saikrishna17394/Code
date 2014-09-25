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
#define ii pair<int,int>

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

int n,q,A[300][300],x1,x2,Y1,y2,ans;
int dp[300][300][11]={0},temp[11];

int main() {
	inp(n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			inp(A[i][j]);


	dp[0][0][A[0][0]]++;
	for(int j=1;j<n;j++) {
		for(int k=1;k<11;k++)
			dp[0][j][k]=dp[0][j-1][k];
		dp[0][j][A[0][j]]++;
	}

	for(int i=1;i<n;i++) {
		memset(temp,0,sizeof temp);
		for(int j=0;j<n;j++) {
			temp[A[i][j]]++;
			for(int k=1;k<11;k++)
				dp[i][j][k]=dp[i-1][j][k]+temp[k];
		}
	}
	inp(q);
	while(q--) {
		inp(x1);
		inp(Y1);
		inp(x2);
		inp(y2);
		x1--;
		Y1--;
		x2--;
		y2--;

		for(int k=1;k<11;k++)
			temp[k]=dp[x2][y2][k];

		if(Y1) {
			for(int k=1;k<11;k++)
				temp[k]-=dp[x2][Y1-1][k];			
		}
		if(x1) {
			for(int k=1;k<11;k++)
				temp[k]-=dp[x1-1][y2][k];			
		}
		if(x1 && Y1) {
			for(int k=1;k<11;k++)
				temp[k]+=dp[x1-1][Y1-1][k];			
		}

		ans=0;
		for(int k=1;k<11;k++)
			if(temp[k])
				ans++;			
		printf("%d\n", ans);
	}
	return 0;
}