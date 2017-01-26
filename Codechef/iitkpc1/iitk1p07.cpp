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

lli mul1(lli a,lli b,lli n) {
	lli ret=0;
	
	while(b!=0) {
		ret+=a*(b%10);
		ret%=n;

		a=(a*10)%n;
		b/=10;
	}
	
	return ret;
}

lli pow1(lli x,lli k,lli n) {
	lli ret=1%n;
	// cout<<x<<" "<<k<<" "<<n<<" : "<<ret<<endl;
	while(k>0) {
		if(k%2==1)
			ret=mul1(ret,x,n);
		x=mul1(x,x,n);
		k/=2;
	}
	// cout<<x<<" "<<k<<" "<<n<<" : "<<ret<<endl;
	return ret;
}


lli solve(lli x,lli m, lli n) {
	// cout<<x<<" "<<m<<" "<<n<<endl;
	if(m==0)
		return 1%n;
	if(m==1)
		return (1+x)%n;


	lli ret=mul1(pow1(x,(m+1)/2,n)+1,solve(x,(m-1)/2,n),n);
	
	if(m%2==0)
		ret=(ret+pow1(x,m,n))%n;
	return ret;
}

int main() {
	lli t,x,n,m;
	inp(t);

	while(t--) {
		inp(x);
		inp(m);
		inp(n);
		// x++;
		// for(int i=0;i<100;i++)
		printf("%lld\n", solve(x,m,n));
	}

	return 0;
}