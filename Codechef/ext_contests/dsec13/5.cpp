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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int main() {
	lli t,n,sum,m,k,num,big,small,ans;

	inp(t);

	while(t--) {
		inp(n);
		inp(m);
		inp(k);
		sum=0;
		big=0;
		for(int i=0;i<n;i++) {
			inp(num);
			num=(m-num)/k+1;

			if(num>big)
				big=num;
			sum+=num;

		}
		sum-=big;

		if(big>sum)
			big=sum;

		ans=big/2;

		if(!(sum&1))
			ans++;
		printf("%lld\n", ans%mod);
	}

	return 0;
}