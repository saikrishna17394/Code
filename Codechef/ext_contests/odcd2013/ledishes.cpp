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
	lli t,n,b,bt,nt,num;


	inp(t);

	for(int i=1;i<=t;i++) {
		inp(num);
		b=3;
		n=4;
		printf("Case:%d\n", i);
		while(b<=num) {
			printf("%lld %lld\n", b,n-b);
			bt=3*b+2*n-2;
			nt=4*b+3*n-3;
			b=bt;
			n=nt;
		}
	}


	return 0;
}