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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli n,k,a,b;
	lli A[100000];

	inp(n);
	inp(k);

	for(int i=0;i<n;i++)
		inp(A[i]);
	a=A[0];
	b=A[0];

	for(int i=0;i<n;i++) {
		a=max(a,A[i]);
		b=min(b,A[i]);
	}

	if(k==0) {
		for(int i=0;i<n;i++)
			printf("%lld ", A[i]);
		printf("\n");
	}
	else if(k%2==1) {
		for(int i=0;i<n;i++) 
			printf("%lld ",a-A[i]);
		printf("\n");
	}
	else {
		for(int i=0;i<n;i++) 
			printf("%lld ",A[i]-b);
		printf("\n");		
	}
	return 0;
}