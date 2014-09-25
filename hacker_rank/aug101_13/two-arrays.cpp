#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
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

int main() {
	int t,n,k,min_a,min_b,num;

	inp(t);

	while(t--) {
		inp(n);
		inp(k);
		min_a=min_b=1000000010;

		for(int i=0;i<n;i++) {
			inp(num);
			min_a=min(min_a,num);
		}
		for(int i=0;i<n;i++) {
			inp(num);
			min_b=min(min_b,num);
		}
		if(min_a+min_b>=k)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}