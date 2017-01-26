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
#define lim 200010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,A[lim],D,d;

int main() {
	inp(n);
	inp(D);
	for(int i=1;i<=n;i++) {
		inp(A[i]);
	}

	while(D--) {
		inp(d);
		map<int,int> m;

		m[A[n]] = n;

		int l=-1,r=-1;
		for(int i = n-1;i>=1;i--) {
			if(m.find(A[i]+d)!=m.end()) {
				int l1=i,r1=m[A[i]+d];
				if(l==-1 || (r-l)>=(r1-l1)) {
					l=l1;
					r=r1;
				}
			}
			m[A[i]]=i;
		}

		if(l==-1)
			printf("-1\n");
		else
			printf("%d %d\n", l,r);
	}

	return 0;
}