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

#define mod 100000000
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
int n;
ii A[100000];
int dp[100000];
int po10[9];

int main() {
	po10[0]=1;
	for(int i=1;i<9;i++)
		po10[i]=10*po10[i-1];

	while(1) {
		inp(n);
		if(n==-1)
			break;
		for(int i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}
		sort(A,A+n);

		dp[n-1]=1;
		// cout<<A[n-1].first<<" "<<A[n-1].second<<" "<<dp[n-1]<<endl;
		for(int i=n-2;i>=0;i--) {
			dp[i]=dp[i+1]+1;

			int l=i+1,r=n-1;
			while(l<r) {
				int mid=(l+r)/2;

				if(A[i].second>A[mid].first)
					l=mid+1;
				else
					r=mid;
			}

			if(A[i].second<=A[l].first)
				dp[i]=(dp[i]+dp[l])%mod;

			// cout<<A[i].first<<" "<<A[i].second<<" "<<dp[i]<<endl;
		}
		
		for(int i=7;i>=0;i--) {
			printf("%d",dp[0]/po10[i]);
			dp[0]%=po10[i];
		}
		printf("\n");
	}
	return 0;
}