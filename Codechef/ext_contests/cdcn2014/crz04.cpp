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

int main() {
	int t,h,m;
	double ans;

	inp(t);

	while(t--) {
		inp(h);
		inp(m);

		if(h>23 || h<0 || m<0 || m>59) {
			printf("Invalid Time\n");
			continue;
		}

		if(h>=12)
			h-=12;

		h*=5;
		int val=abs(m-h);
		val*=6;
		// cout<<val<<endl;
		// val=min(val,360-val);
		double val1=m;
		val1/=2.0;
		ans=val;
		if(m>h)
			ans-=val1;
		else
			ans+=val1;
		// cout<<ans<<endl;
		ans=min(ans,360.0-ans);
		// ans=min(ans,360.0-ans);
		printf("%.1f\n", ans);
	}

	return 0;
}