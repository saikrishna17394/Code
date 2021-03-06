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
#define vvi vector<vector<long long int> >

#define mod 1000000007
#define inf 999999999
#define lim 1000001

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,a,b;

int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	inp(t);

	while(t--) {
		inp(a);
		inp(b);
		while(1) {
			int g=gcd(a,b);
			a/=g;
			b/=g;
			if(a==b)
				break;
			if(a>b) {
				printf("R");
				a-=b;
				swap(a,b);
			}
			else {
				printf("L");
				swap(a,b);
				a-=b;
			}
		}
		printf("\n");
	}

	return 0;
}