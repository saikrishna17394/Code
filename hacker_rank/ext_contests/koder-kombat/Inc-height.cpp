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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,h,pre;

int main() {
	inp(t);

	while(t--) {
		int ans=1;
		inp(n);

		inp(pre);

		int i;
		for(i=1;i<n;i++) {
			inp(h);
			if(h>pre)
				ans++;
			else
				break;
			pre=h;
		}
		i++;
		printf("%d\n", ans);
		for(;i<n;i++)
			inp(h);
	}

	return 0;
}