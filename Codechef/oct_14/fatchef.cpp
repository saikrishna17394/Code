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
int t,n,m;
ii B[100000];

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		for(int i=0;i<m;i++) {
			char c;
			cin>>c;
			B[i].second=c;
			inp(B[i].first);
		}
		sort(B,B+m);
		lli ans=1;

		for(int i=1;i<m;i++) {
			if(B[i].second!=B[i-1].second) {
				ans=(ans*(lli)(B[i].first-B[i-1].first))%mod;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}