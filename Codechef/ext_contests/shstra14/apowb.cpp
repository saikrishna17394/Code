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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli pow1(lli n,int k) {
	lli ret=1;
	while(k) {
		if(k&1)
			ret=ret*n;
		n=n*n;
		k>>=1;
	}
	return ret;
}

int main() {
	lli t,n,num;
	inp(t);

	while(t--) {
		inp(n);
		num=sqrt(n);

		bool ok=false;

		num=max(num-2,(lli)0);
		for(lli i=num;i<(num+6);i++) 
			if(i*i==n)
				ok=true;

		lli l=1,r=1000000;

		while(l<r) {
			lli mid=(l+r)/2;
			lli val=pow1(mid,3);
			if(val>=n)
				r=mid;
			else
				l=mid+1;
		}

		if(pow1(l,3)==n)
			ok=true;
		for(int i=5;i<60;i+=2) {
			for(lli j=1;;j++) {
				lli val=pow1(j,i);
				if(val>n)
					break;
				if(val==n) {
					ok=true;
					break;
				}
			}
			if(ok)
				break;
		}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}