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

int main() {
	int n,A[1000000],dp[1000000],ans,len;

	inp(n);
	ans=n;

	for(int i=0;i<n;i++)
		inp(A[i]);

	if(n==1) {
		printf("0\n");
		return 0;
	}

	dp[0]=1;

	vector<ii> v;
	v.push_back(ii(A[0],0));
	len=1;

	ans=n-1;
	for(int i=1;i<n;i++) {
		dp[i]=1;
		if(A[i]<=i)
			continue;
		for(int j=0;j<len;j++) {
			if((A[i]-v[j].first)>=(i-v[j].second))
				dp[i]=max(dp[i],1+dp[v[j].second]);
		}
		ans=min(ans,n-dp[i]);
		if(A[i]>i) {
			v.push_back(ii(A[i],i));
			len++;
		}
	}
	printf("%d\n", ans);
	return 0;
}