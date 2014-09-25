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
#define ii pair<long long int,long long int>

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

lli f(lli m,lli n) {
	cout<<m<<" "<<n<<" "<<endl;
	lli ret=n/m;
	ret*=m;
	ret*=(m-1);

	if(n%m==0) {
		return ret;
	}

	return ret+f(m,n%m);
}
int main() {
	lli t,n,m;
	inp(t);

	while(t--) {
		inp(m);
		inp(n);
		printf("%lld\n", f(m,n));
	}


	return 0;
}