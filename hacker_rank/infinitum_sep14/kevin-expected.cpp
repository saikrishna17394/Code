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

#define mod 100
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

double dp[5000001];
lli t,n;

int main() {
	dp[0]=0;

	for(int i=1;i<5000001;i++) {
		dp[i]=dp[i-1];
		double val=sqrt(4*i+1);
		val+=1.0;
		val/=2.0;
		dp[i]+=val;
	}

	inp(t);
	while(t--) {
		inp(n);
		if(n<5000001)
			printf("%.11f\n", dp[n-1]/(double)n);
		else
			
	}
	return 0;
}