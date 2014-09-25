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
	int t,n,m,k,val,ans;
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(k);

		// ans=0;
		// val=1+n/2;

		// ans=val*(1+m/2);

		// cout<<ans<<endl;
		// val=(1+n)/2;

		// ans+=val*((1+m)/2);

		// cout<<ans<<endl;
		// ans=(1+n/2)*(1+m/2);
		if(k>n*m)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}