#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
#define x getchar_unlocked()
#define mod 10000000000
using namespace std;
 
inline void inp(int &n ) {//fast input function
    n=0;
    int ch=x,sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=x;
    n=n*sign;
}

lli pow(lli a,lli n) {
	if(n==0)
		return 1;
	lli k=pow(a,n/2);
	k=(k*k)%mod;
	if(n%2==0)
		return k;
	return (k*a)%mod;
}

int main() {
	lli ans=pow(2,7830457);
	cout<<ans<<endl;
	ans=1;
	for(int i=0;i<7830457;i++)
		ans=(ans*2)%mod;
	cout<<ans<<endl;
	ans=(ans*28433)%mod;
	ans=(ans+1)%mod;

	cout<<ans<<endl;
	return 0;
}