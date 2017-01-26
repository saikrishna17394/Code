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
#define inf (lli)1e16

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int t,n,A[15];
int dp[1<<15];

int solve(int mask) {
	int & ret=dp[mask];
	if(ret!=-1)
		return ret;

	int num=mask;
	int B[15],idx=0;
	for(int i=0;i<n;i++) {
		if(num%2==1)
			B[idx++]=A[i];
		num/=2;
	}
	bool ok=true;

	for(int i=1;i<idx;i++) {
		if(B[i]<B[i-1])
			ok=false;
	}
	if(ok) {
		ret=0;
		return ret;
	}


	num=mask;
	idx=0;
	for(int i=0;i<n;i++) {
		if(num%2==1) {
			B[idx++]=solve(mask^(1<<i));
		}
		num/=2;
	}
	sort(B,B+idx);

	ret=0;

	for(int i=0;i<idx;i++) {
		if(B[i]>ret)
			break;
		if(B[i]==ret)
			ret++;
	}
	return ret;
}
int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(int i=0;i<n;i++)
			inp(A[i]);
		memset(dp,-1,sizeof dp);

		if(solve((1<<n)-1)==0)
			printf("Bob\n");
		else
			printf("Alice\n");
		// for(int i=0;i<n;i++)
		// 	for(int j=i;j<n;j++)
		// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	}

	return 0;
}