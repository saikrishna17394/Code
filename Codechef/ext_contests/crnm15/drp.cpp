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

int n,x;

int main() {
	inp(n);

	while(n--) {
		inp(x);

		double eps=1e-1;
		double ans;

		if(x<=100) {
			ans=0;
		}
		else {
			x-=100;
			ans=eps*(double)x;
			double val=20;
			ans/=val;

		}
		printf("%.6f\n", ans);
	}

	return 0;
}