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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli pow2[41],dp[41][41],t,n,m,C[40],P[40];

map<lli,lli> m1;

double ans;

int main() {
	pow2[0]=1;
	
	for(int i=1;i<41;i++)
		pow2[i]=2*pow2[i-1];

	memset(dp,0,sizeof dp);
	dp[0][0]=1;

	for(int i=1;i<41;i++) {
		dp[i][0]=1;
		for(int j=1;j<=i;j++)
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
	}

	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		m1.clear();

		for(int i=0;i<n;i++) {
			inp(C[i]);
			inp(P[i]);
			if(m1.find(C[i])==m1.end())
				m1[C[i]]=1;
			else
				m1[C[i]]++;
		}

		lli val=0,val1=0;

		int num=m1.size();

		for(int i=m;i<=num;i++)
			val1+=dp[num][i];
		



		printf("%.6f\n", ans);
	}
	return 0;
}
