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

lli fun(lli k,lli n) {
	lli ret=1;
	while(k) {
		ret=(ret*10)%n;
		k--;
	}
	ret=(ret*4)%n;
	return ret;
}

int main() {
	lli t,n,A[100000]={0},num,val;
	lli ans,a,b,kri;

	inp(t);


	while(t--) {
		inp(n);

		b=0;

		while(n%10==0) {
			b++;
			n/=10;		
		}

		if(n%2==0) {

			val=0;
			while(n%2==0) {
				n/=2;
				val++;
			}

			val-=2;
			val=max(val,(lli)0);

			b+=val;
			a=1;

			val=4%n;
			// cout<<val<<" "<<n<<endl;
			while(val) {

				val=(val*10)%n;
				val=(val+4)%n;
				a++;
			}

			printf("%lld\n",2*a+b);

		}
		else {

			while(n%5==0) {
				n/=5;
				b++;
			}

			a=1;

			val=4%n;
			// cout<<val<<" "<<n<<endl;
			while(val) {

				val=(val*10)%n;
				val=(val+4)%n;
				a++;
			}

			printf("%lld\n",2*a+b);

		}
	}

	return 0;
}