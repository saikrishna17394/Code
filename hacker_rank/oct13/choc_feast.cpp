#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	int n,c,m,ans,t,val,wrappers;

	inp(t);
	while(t--) {
		inp(n);
		inp(c);
		inp(m);

		ans=n/c;
		// cout<<ans<<endl;
		wrappers=ans;
		while(wrappers>=m) {
			ans=ans+wrappers/m;

			val=wrappers/m;
			val+=wrappers%m;
			wrappers=val;
		}
		printf("%d\n", ans);
	}
	return 0;
}