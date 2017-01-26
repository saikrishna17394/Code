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
#define inf 1999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

lli power(lli n,lli k) {
	lli ret=1;
	n%=mod;
	while(k>0) {
		if(k%2==1)
			ret=(ret*n)%mod;
		n=(n*n)%mod;
		k/=2;
	}
	return ret;
}

lli t,n,m;

int main() {
	cin>>t;

	while(t--) {
		cin>>n>>m;
		if(n==1)
			cout<<m<<endl;
		else if(n==2) {
			cout<<(m*(m-1))%mod<<endl;
		}
		else {
			lli ans=(m*(m-1))%mod;
			ans*=power(m-2,n-2);
			ans%=mod;
			cout<<ans<<endl;
		}
	}

	return 0;
}