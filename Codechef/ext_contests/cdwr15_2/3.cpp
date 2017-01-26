#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999
#define lim 10000

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,n;
ii A[100];


int main() {
	inp(t);

	while(t--) {
		inp(n);

		for(lli i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}

		sort(A,A+n);

		

		printf("%lld,%lld\n", A[0].first,A[0].second);

		int start=0;
		int p=0;

		do {
			int nxt=-1;

			for(int i=0;i<n;i++) {
				if(i==p)
					continue;
				if(nxt==-1) {
					nxt=i;
					continue;
				}

				lli a1=A[nxt].first-A[p].first;
				lli b1=A[nxt].second-A[p].second;
				lli a2=A[i].first-A[p].first;
				lli b2=A[i].second-A[p].second;

				lli cross=a1*b2-a2*b1;

				if(cross<0)
					nxt=i;
			}
			p=nxt;

			printf("%lld,%lld\n", A[p].first,A[p].second);
		} while(start!=p);

	}
	return 0;
}