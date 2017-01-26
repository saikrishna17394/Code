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

int t,n;
ii A[10000];
int dp[10000];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}

		sort(A,A+n);

		dp[n-1]=1;

		for(int i=n-2;i>=0;i--) {
			int l=i+1,r=n-1;

			while(l<r) {
				int m=(l+r)/2;
				if(A[m].first>A[i].second)
					r=m;
				else
					l=m+1;
			}
			dp[i]=dp[i+1];

			if(A[l].first>A[i].second)
				dp[i]=max(dp[i],dp[l]+1);

		}

		printf("%d\n", dp[0]);
	}


	return 0;
}