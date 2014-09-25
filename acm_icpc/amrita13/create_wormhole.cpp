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
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli t,n,A[10000],ans,sum;

	inp(t);

	while(t--) {
		inp(n);

		for(int i=0;i<n;i++)
			inp(A[i]);

		sort(A,A+n);

		sum=0;

		for(int i=0;i<n;i++)
			sum+=A[i];

		int a;
		for(a=n-1;a>=2;a--) {
			sum-=A[a];
			if(A[a]<sum) {
				printf("%d\n", a+1);
				break;
			}
		}

		if(a>1)
			continue;
		printf("-1\n");
	}

	return 0;
}