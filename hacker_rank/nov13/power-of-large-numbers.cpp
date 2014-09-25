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
lli process(string s) {
	int len=s.length();
	lli ret=0;
	for(int i=0;i<len;i++) {
		ret=ret*10+s[i]-'0';
		ret%=mod;
	}
	return ret;
}
lli process1(string s) {
	int len=s.length();
	lli ret=0;
	for(int i=0;i<len;i++) {
		ret=ret*10+s[i]-'0';
		ret%=(mod-1);
	}
	return ret;
}

lli pow(lli x,lli n) {
	lli ret=1;
	while(n) {
		if(n&1)
			ret=(ret*x)%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return ret;
}

int main() {
	lli t,a,b;
	string s;
	inp(t);

	while(t--) {
		cin>>s;
		a=process(s);
		cin>>s;
		b=process1(s);
		printf("%lld\n", pow(a,b));
	}

	return 0;
}