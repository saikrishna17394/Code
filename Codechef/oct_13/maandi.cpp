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

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

bool check(int n) {
	while(n) {
		if(n%10==4 || n%10==7)
			return true;
		n/=10;
	}
	return false;
}
int main() {
	int t,n,ans;

	inp(t);

	while(t--) {
		inp(n);
		ans=0;
		int i=1;

		for(;i*i<n;i++) {
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