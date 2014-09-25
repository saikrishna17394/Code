#include <iostream>
#include <cstdio>
#include <cmath>
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
	int t,t1,t2,t3,t4;
	double ans;
	inp(t);
	while(t--) {
		inp(t1);
		inp(t2);
		inp(t3);
		inp(t4);
		ans=(double)t1/(double)(t1+t2);
		printf("%.7f\n",ans);
	}
	return 0;
}