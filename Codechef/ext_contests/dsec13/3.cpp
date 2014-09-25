#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int t,n,A[7000],suf[7000],ans;
	inp(t);
	while(t--) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i]);
		}
		suf[0]=A[0];

		for(int i=1;i<n;i++) {
			suf[i]=max(A[i],A[i]+suf[i-1]);
		}
		ans=-inf;

		for(int i=0;i<n;i++)
			ans=max(ans,suf[i]);

		printf("%d\n", ans);
	}
	return 0;
}