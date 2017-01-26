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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli t,x,k;
int main() {
	inp(t);

	while(t--) {
		inp(x);
		inp(k);

		double val=0.5;
		double ans=0;
		while(k!=1) {
			ans*=0.5;
			if(k%2==1)
				ans+=0.5;
			k/=2;
			val*=0.5;
		}
		ans+=val;
		
		printf("%.6f\n", ans*(double)x);
	}

	return 0;
}