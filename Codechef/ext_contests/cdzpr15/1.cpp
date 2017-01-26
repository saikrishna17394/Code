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

int main() {
	int t,n,k;

	inp(t);

	while(t--) {
		inp(n);
		inp(k);

		int val=n*(n+1);
		val/=2;

		int ans=inf;

		val=val-k;

		for(int i=1;i<=n;i++) {

			if((val-i)>=1 && (val-i)<=n && (2*i)!=val)
				ans=min(ans,i*(val-i));
		}

		if(ans!=inf)
			cout<<ans<<endl;
		else
			printf("-1\n");
	}

	return 0;
}