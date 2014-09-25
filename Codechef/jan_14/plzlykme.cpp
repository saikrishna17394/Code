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
#define lim 100010
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
	lli t,l,d,s,c,num;

	inp(t);

	while(t--) {
		inp(l);
		inp(d);
		inp(s);
		inp(c);
		d--;
		while(d--) {
			if(s>=l)
				break;
			s=s*(1+c);
		}

		if(s>=l)
			printf("ALIVE AND KICKING\n");
		else
			printf("DEAD AND ROTTING\n");
	}

	return 0;
}