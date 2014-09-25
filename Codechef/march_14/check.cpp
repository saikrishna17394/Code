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

#define mod 1000000009
#define inf 999999999
#define MAXN 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,m,g,x,y,A[MAXN];

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	inp(n);
	inp(m);

	for(int i=1;i<=n;i++)
		inp(A[i]);

	while(m--) {
		inp(g);
		inp(x);
		inp(y);
		map<int,int> m1;
		m1.clear();
		for(int i=x;i<=y;i++) {
			if(gcd(A[i],g)>1)
				m1[A[i]]++;
		}
		if(m1.size()==0)
			printf("-1 -1\n");
		else
			printf("%d %d\n",m1.rbegin()->first,m1.rbegin()->second );
	}
	return 0;
}