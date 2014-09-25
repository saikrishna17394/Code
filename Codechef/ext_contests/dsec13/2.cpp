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

bool check(int n) {
	while(n) {
		int a=n%10;
		if(a==3 || a==5 || a==6)
			return true;
		n/=10;
	}
	return false;
}
int main() {
	int t,n,ans,i;

	inp(t);

	while(t--) {
		inp(n);
		ans=0;

		for(i=1;i*i<n;i++) {
			if(n%i==0) {
				if(check(i))
					ans++;
				if(check(n/i))
					ans++;
			}
		}

		if(i*i==n && check(i))
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}