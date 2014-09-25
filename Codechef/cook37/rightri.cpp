#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
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

int dist(int a,int y) {
	return a*a+y*y;
}

int main() {
	int n,ans=0,x1,y1,x2,y2,x3,y3,A[3];
	inp(n);
	while(n--) {
		inp(x1);inp(y1);
		inp(x2);inp(y2);
		inp(x3);inp(y3);

		A[0]=dist(x2-x1,y2-y1);
		A[1]=dist(x3-x1,y3-y1);
		A[2]=dist(x3-x2,y3-y2);

		sort(A,A+3);

		if(A[2]==A[1]+A[0])
			ans++;
	}

	printf("%d\n",ans);
	return 0;
}
