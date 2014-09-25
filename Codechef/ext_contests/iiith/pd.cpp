#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <queue>
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
	lli n,A[100000],val,ans;

	inp(n);
	for(int i=0;i<n;i++)
		inp(A[i]);

	sort(A,A+n);

	val=ans=0;

	ans=A[n-1];
	val=1;
	for(int i=n-2;i>=0;i--) {
		if(val && A[i]<A[i+1]) {
			val--;
		}
		else {
			ans+=A[i];
			val++;
		}
	}

	printf("%lld\n", ans);
	return 0;
}