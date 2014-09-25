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

int t,n,A[100000],a,b,c,d;

lli ans;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		a=0;b=0;
		c=0;d=0;
		for(int i=0;i<n;i++) {
			inp(A[i]);
			if(A[i]==0)
				a++;
			else if(A[i]==1)
				b++;
			else if(A[i]==2)
				c++;
			else
				d++;
		}

		ans=0;

		for(int i=0;i<n;i++) {
			if(A[i]==0) {
				a--;
			}
			else if(A[i]==1) {
				b--;
			}
			else if(A[i]==2) {
				c--;
				ans+=(lli)(d);
			}
			else {
				d--;
				ans+=(lli)(c+d);
			}

		}
		printf("%lld\n", ans);
	}

	return 0;
}