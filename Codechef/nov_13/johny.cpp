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
#define ii pair<long long int,long long int>

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

int main() {
	int t,n,A[1000],k,num,ans;
	inp(t);

	while(t--) {
		inp(n);
		for(int i=0;i<n;i++)
			inp(A[i]);
		inp(k);
		num=A[k-1];

		sort(A,A+n);
		ans=(int)(lower_bound(A,A+n,num)-A);
		ans++;
		printf("%d\n", ans);
	}
	return 0;
}