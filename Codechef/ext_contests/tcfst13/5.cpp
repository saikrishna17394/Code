#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <list>
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
int n;
double A[100000],dp[100000],ans;

int main() {
	inp(n);
	ans=0;
	for(int i=0;i<n;i++) {
		cin>>A[i];
		ans+=A[i];
	}

	if(n==1)
		;
	else {
		dp[n-2]=A[n-1]*A[n-2];
		// cout<<ans<<endl;
		ans+=(2.0*dp[n-2]);
		// cout<<ans<<endl;
		for(int i=n-3;i>=0;i--) {
			dp[i]=(A[i]*dp[i+1]+A[i]*A[i+1]);
			ans+=dp[i]*2.0;
		}
	}
	printf("%.6f\n", ans);
	return 0;
}