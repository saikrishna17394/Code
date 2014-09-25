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

int area(int x1,int y1,int x2,int y2) {
	return abs(x1*y2-x2*y1);
}

int main() {
	int n,small=inf,big=0,l=0,r=0;
	int x1,y1,x2,y2,x3,y3,val;
	inp(n);

	for(int i=1;i<=n;i++) {
		inp(x1);
		inp(y1);
		inp(x2);
		inp(y2);
		inp(x3);
		inp(y3);

		val=area(x2-x1,y2-y1,x3-x1,y3-y1);

		if(val>=big) {
			r=i;
			big=val;
		}
		if(val<=small) {
			l=i;
			small=val;
		}
	}

	printf("%d %d\n", l,r);

	return 0;
}