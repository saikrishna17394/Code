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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,R,G,B,m,r,g,b,A[3],x,ans;

int main() {
	inp(t);

	while(t--) {
		inp(R);
		inp(G);
		inp(B);
		inp(m);

		r=0;
		while(R--) {
			inp(x);
			r=max(r,x);
		}
		g=0;
		while(G--) {
			inp(x);
			g=max(g,x);
		}
		b=0;
		while(B--) {
			inp(x);
			b=max(b,x);
		}

		A[0]=r;
		A[1]=g;
		A[2]=b;
		sort(A,A+3);
		ans=A[2];

		while(m--) {
			A[2]/=2;
			// A[0]++;
			// A[1]++;
			sort(A,A+3);
			ans=min(ans,A[2]);
		}
		printf("%d\n", ans);
	}

	return 0;
}