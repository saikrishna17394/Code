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

int t,n,A[100],ans;

int main() {
	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		for(int i=0;i<n;i++)
			inp(A[i]);
		sort(A,A+n);
		ans=0;
		ans=A[n-1]+A[n-2]+A[n-3];
		printf("Case %d: %d\n",a, ans);
	}

	return 0;
}