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

#define mod 1008
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

int dp[100000],vis[1008];

int main() {
	lli t,n;

	inp(t);

	while(t--) {
		inp(n);
		if(n==1)
			printf("1\n");
		else if(n==2)
			printf("4\n");
		else if(n==3)
			printf("85\n");
		else if(n&1)
			printf("589\n");
		else
			printf("508\n");
	}


	return 0;
}