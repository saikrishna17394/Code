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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	int t,t1,t2,d,num;
	double ans,val1;
	int val;
	inp(t);
	while(t--) {
		inp(t1);
		t1*=60;
		inp(num);
		t1+=num;
		inp(t2);
		t2*=60;
		inp(num);
		t2+=num;
		inp(d);

		val=t1-t2;
		val+=d;
		ans=val;
		printf("%.1f ",ans );

		if(t2+2*d<=t1) {
			ans=(double)(t1-t2);
		}
		else {
			val1=t1-t2;
			val1/=2.0;
			val1+=(double)d;
			val1+=(double)t2;
			ans=val1;
			ans-=(double)t2;
		}
		printf("%.1f\n",ans);
	}
	return 0;
}