#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define lli long long int
#define mod 1000000007
#define inf 1e10
#define ii pair<int,int>
#define pii pair<double,pair<int,int> >
#define mp make_pair

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,x,y,n;

int main() {
	inp(t);

	inp(n);

	while(t--) {
		inp(x);
		inp(y);
		int ans=1;

		for(int i=0;i<y;i++)
			ans=(ans*x)%n;
		printf("%d\n", ans);
	}
	return 0;
}