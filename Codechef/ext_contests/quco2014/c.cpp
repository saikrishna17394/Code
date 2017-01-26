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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t;


int h,m,s,val;

int main() {
	inp(t);

	while(t--) {
		inp(val);
		h=val/100;
		m=val%100;
		inp(s);
		int cur1=h*60+m+s/60;
		s+=59;



		int cur=h*60+m+s/60;

		cur%=1440;
		cur1%=1440;

		cur=max(cur,cur1);



		h=cur/60;

		if(h<10)
			printf("0%d",h );
		else
			printf("%d",h );

		m=cur%60;

		if(m<10)
			printf("0%d\n", m);
		else
			printf("%d\n", m);
	}

	return 0;
}