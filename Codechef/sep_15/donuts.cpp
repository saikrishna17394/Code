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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n;
int m,A[lim];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<m;i++)
			inp(A[i]);

		sort(A,A+m);

		int l=0,r=m-1;
		int ans=0;

		while(l<r) {
			if((l+1)<r) {
				A[r-1]+=A[r];
				A[r-1]++;

				A[l]--;
				if(A[l]==0)
					l++;
				r--;
				ans++;
			}
			else {
				r--;
				ans++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}