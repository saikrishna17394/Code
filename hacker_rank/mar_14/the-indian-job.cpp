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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int t,n,g,A[100],dp[100][10001],sum;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(g);

		sum=0;

		for(int i=0;i<n;i++) {
			inp(A[i]);
			sum+=A[i];
		}

		memset(dp,0,sizeof dp);

		dp[0][A[0]]=1;

		for(int i=1;i<n;i++) {
			for(int j=0;j<10001;j++) {
				if(j>=A[i] && dp[i-1][j-A[i]]==1)
					dp[i][j]=1;
				if((A[i]+j)<10001 && dp[i-1][A[i]+j]==1)
					dp[i][j]=1;
				if(A[i]>=j && dp[i-1][A[i]-j]==1)
					dp[i][j]=1;
				// if(dp[i][j])
				// 	cout<<i<<" "<<j<<endl;
			}
		}

		int val=inf;

		for(int j=0;j<10001;j++) {
			if(dp[n-1][j]) {
				val=j;
				break;
			}
		}

		int ans=(sum+val)/2;
		// cout<<ans<<" "<<g<<endl;
		if(ans<=g)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}