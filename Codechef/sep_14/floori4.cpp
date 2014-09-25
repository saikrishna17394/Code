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
#include <iomanip>
#define lli long long int
#define ii pair<int,int>

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


lli m,n,t,ans;

lli solve1(lli i) {

	lli base=30*m;

	i%=base;
	lli ret=0,val=i;
	ret=-i;
	val=(val*i)%base;
	val=(val*i)%base;
	ret=(ret+10*val)%base;
	val=(val*i)%base;
	ret=(ret+15*val)%base;
	val=(val*i)%base;
	ret=(ret+6*val)%base;
	if(ret<0)
		ret+=base;
	// cout<<"solve1 "<<i<<" "<<ret/30<<endl;
	return ret/30;
}
lli solve(lli i,lli j) {
	// cout<<i<<" "<<j<<" ";
	lli ret=solve1(j);
	ret-=solve1(i-1);
	ret%=m;
	if(ret<0)
		ret+=m;
	// cout<<ret<<endl;
	return ret;
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		ans=0;

		lli num;

		for(lli i=1;i*i<=n;i++) {
			lli val=n/i;
			for(int j=0;j<4;j++)
				val=(val*i)%m;
			ans+=val;
			// cout<<i<<" "<<val<<endl;
			ans%=m;
			num=i+1;
		}

		while(num<=n) {
			// cout<<n/num<<" ";
			lli val=(n/num)*solve(num,num+(n%num)/(n/num));
			val%=m;
			ans+=val;
			ans%=m;
			num+=(n%num)/(n/num);
			num++;
		}

		printf("%lld\n", ans);
	}

	return 0;
}