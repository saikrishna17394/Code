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
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main() {
	lli n,t,lim,a,b,c;
	lim=(lli)1e10;

	set<lli> s;

	a=1;
	b=1;
	s.insert((lli)1);
	c=2;

	while(c<=lim) {
		s.insert(a+b);
		a=b;
		b=c;
		c=a+b;
	}

	inp(t);

	while(t--) {
		inp(n);
		if(s.find(n)==s.end())
			printf("IsNotFibo\n");
		else
			printf("IsFibo\n");
	}

	return 0;
}