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

int t;
int a,b,c,d;

int main() {
	inp(t);

	while(t--) {
		inp(a);
		inp(b);
		inp(c);
		inp(d);

		c-=a;
		d-=b;

		int ans;

		if(c==0) {
			ans=max(0,abs(d)-1);
		}
		else {
			ans=0;
			d=abs(d);
			c=abs(c);
			for(int i=1;i<c;i++) {
				if((d*i)%c==0)
					ans++;
			}
		}
		printf("%d\n", ans);
	}	

	return 0;
}