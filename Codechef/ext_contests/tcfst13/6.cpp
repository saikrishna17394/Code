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

int main() {
	int n,A[100000],B[100000],C[100000],ans;

	inp(n);

	inp(A[0]);
	B[0]=0;
	if(A[0]>=0)
		B[0]++;
	// cout<<B[0]<<endl;
	for(int i=1;i<n;i++) {
		inp(A[i]);
		B[i]=B[i-1];
		if(A[i]>=0)
			B[i]++;
	}
	C[n-1]=0;
	if(A[n-1]<=0)
		C[n-1]++;

	for(int i=n-2;i>=0;i--) {
		C[i]=C[i+1];
		if(A[i]<=0)
			C[i]++;
	}
	ans=inf;
	for(int i=0;i<(n-1);i++) {
		// cout<<i<<endl;
		// cout<<B[i]<<" "<<C[i+1]<<endl;
		ans=min(ans,B[i]+C[i+1]);
	}
	printf("%d\n", ans);
	return 0;
}