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


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	int t,a,b,c;

	inp(t);

	while(t--) {
		inp(a);
		inp(b);
		inp(c);

		if(c>=a && c>=b)
			printf("NO\n");
		else if(c%gcd(a,b)==0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}