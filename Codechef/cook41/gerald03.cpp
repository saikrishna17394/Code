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
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 100010
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

void solve(int a,int b,int a1,int b1) {
	if(a!=a1) {
		if(a<a1 && (a+1)!=b ) {
			printf("L+");
			solve(a+1,b,a1,b1);
			return;
		}
		if(a>a1 && (a-1)!=b) {
			printf("L-");
			solve(a-1,b,a1,b1);
			return;
		}
	}
	if(b!=b1) {
		if(b<b1 && (b+1)!=a ) {
			printf("R+");
			solve(a,b+1,a1,b1);
			return;
		}
		if(b>b1 && (b-1)!=a) {
			printf("R-");
			solve(a,b-1,a1,b1);
			return;
		}
	}
	return;
}
int main() {
	int t,n,ans;
	inp(t);
	ii A[1000];
	while(t--) {
		inp(n);
		for(int i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}
		if(n==1) {
			printf("0\n");
			printf("\n");
			continue;
		}
		ans=0;
		for(int i=1;i<n;i++) {
			ans+=abs(A[i].first-A[i-1].first);
			ans+=abs(A[i].second-A[i-1].second);
		}
		printf("%d\n", ans);
		for(int i=1;i<n;i++) {
			solve(A[i-1].first,A[i-1].second,A[i].first,A[i].second);
		}
		printf("\n");
	}

	return 0;
}