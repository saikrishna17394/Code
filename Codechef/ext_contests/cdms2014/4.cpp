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

int dp[1000];
int main() {
	int t,n;
	inp(t);

	dp[0]=1;
	dp[1]=2;
	dp[2]=4;
	int val=3;
	for(int i=3;;i++) {
		dp[i]=dp[i-1]+val;
		val++;
		if(dp[i]>=1000)
			break;
	}
	while(t--) {
		inp(n);
		int idx=0;
		while(1) {
			if(dp[idx]>=n) {
				printf("%d\n", idx);
				break;
			}
			idx++;
		}
	}

	return 0;
}