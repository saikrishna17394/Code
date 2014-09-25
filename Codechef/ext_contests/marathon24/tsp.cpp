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
#define inf 1999999999
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
	int n,m,a,b,g[1001][1001],ans=inf;

	inp(n);
	inp(m);
	memset(g,-1,sizeof g);

	while(m--) {
		inp(a);
		inp(b);
		inp(g[a][b]);
	}

	for(int i=1;i<=n;i++) {
		
	}
	return 0;
}