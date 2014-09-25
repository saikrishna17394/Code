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

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int t,n,A[100000];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			inp(A[i]);

		int g=A[0];

		for(int i=1;i<n;i++)
			g=gcd(g,A[i]);

		if(g==1)
			printf("%d\n", n);
		else
			printf("-1\n");
	}
	return 0;
}