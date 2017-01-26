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
#define lim 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}


lli solve(lli n) {
	if(n==1)
		return 1;
	if(n%2==0) {
		lli ret=solve(n/2);
		ret*=2;
		ret-=1;
		return ret;
	}
	else {
		lli ret=solve((n+1)/2);

		if(ret==1) {
			return n;
		}
		else {
			ret*=2;
			ret-=3;
			return ret; 
		}
	}
}
lli t,n;
int main() {
	cin>>t;

	while(t--) {
		cin>>n;
		printf("%lld\n", solve(n));

	}


	return 0;
}