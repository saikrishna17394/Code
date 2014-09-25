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
	int t,n,a,b;

	inp(t);

	while(t--) {
		inp(n);
		a=0;
		b=0;

		while(n>1) {
			if(n&1)
				b++;
			a++;
			n>>=1;
		}

		if(b==0)
			printf("%d\n", max(a-1,0));
		else {
			b--;
			printf("%d\n", a+b/2);
		}
	}


	return 0;
}