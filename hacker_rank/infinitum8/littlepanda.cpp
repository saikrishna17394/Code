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

// returns gcd(a,b) 
// and x,y store the solution of the eqn. 
// ax+by=gcd(a,b).
int ex_gcd(int a,int b,int& x,int& y) {
	
	int s,t,r,old_s,old_r,old_t,temp;

	s=0;old_s=1;
	t=1;old_t=0;
	r=b;old_r=a;

	while(r>0) {
		int q=old_r/r;

		temp=r;
		r=old_r-q*r;
		old_r=temp;

		temp=s;
		s=old_s-q*s;
		old_s=temp;

		temp=t;
		t=old_t-q*t;
		old_t=temp;
	}

	x=old_s;
	y=old_t;

	return old_r;
}

// return x such that
// ax = 1 mod p
int inv(int a,int p) {
	int x,y;
	// no inverse exists because
	// 'a' and 'p' are not co-prime
	if(ex_gcd(a,p,x,y)!=1)
		return -1;
	// The below steps are necessary
	x%=p;
	if(x<0)
		x+=p;
	return x;
}

lli power(lli n,lli k,lli p) {
	lli ret=1%p;

	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%p;
		n=(n*n)%p;
		k/=2;
	}
	return ret;
}
lli t,a,b,x;

int main() {
	inp(t);

	while(t--) {
		inp(a);
		inp(b);
		inp(x);

		if(b>=0)
			printf("%lld\n", power(a,b,x));
		else {
			a=(lli)inv((int)a,(int)x);
			printf("%lld\n", power(a,-b,x));			
		}
	}


	return 0;
}