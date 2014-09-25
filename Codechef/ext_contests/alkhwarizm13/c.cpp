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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int t,n,x,y;
	set<int> s1,s2;

	lli ans;

	inp(t);

	while(t--) {
		inp(n);

		s1.clear();
		s2.clear();
		for(int i=0;i<n;i++) {
			inp(x);
			inp(y);
			s1.insert(x);
			s2.insert(y);
		}

		ans=s1.size()+1;
		ans*=(lli)(s2.size()+1);

		printf("%lld\n", ans);
	}
	return 0;
}