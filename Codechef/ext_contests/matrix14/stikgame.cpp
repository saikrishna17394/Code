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

int A[2000],n;

int solve(int l,int r,int val) {
	if(l>r)
		return 0;
	int ret=0;
	int idx=l;

	while(l<r) {
		int m=(l+r)/2;
		if(A[m]>val)
			r=m;
		else
			l=m+1;
	}
	if(A[l]<=val)
		return 0;

	return n-l;
}

int main() {
	while(1) {
		inp(n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			inp(A[i]);

		sort(A,A+n);

		lli ans=0;

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans+=(lli)solve(j+1,n-1,A[i]+A[j]);

		printf("%lld\n", ans);
	}
	return 0;
}