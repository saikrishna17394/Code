#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>
#include <algorithm>
#define x getchar_unlocked()
using namespace std;

inline void inp( int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}


int main() {
	int t,n,m,w;
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(w);
	}

	return 0;
}