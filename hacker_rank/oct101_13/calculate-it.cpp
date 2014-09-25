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

map<lli,lli> m;
lli n,k;

lli hrank(lli i) {
	// cout<<i<<endl;
	if(i<k)
		return 1;
	i=i-i%k;
	
	if(m.find(i)!=m.end())
		return m[i];
	lli ret;

	ret=hrank(i-k)+hrank(i/k);
	m[i]=ret;
	return ret;
}
int main() {
	inp(k);
	inp(n);

	printf("%lld\n", hrank(n));
	return 0;
}