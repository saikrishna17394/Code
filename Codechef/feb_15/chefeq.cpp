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

int t,n,A[lim];

int main() {
	inp(t);

	while(t--) {
		inp(n);

		map<int,int> m;

		for(int i=0;i<n;i++) {
			inp(A[i]);
			m[A[i]]++;
		}

		int ans=n-1;

		for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
			ans=min(ans,n-it->second);
		}

		printf("%d\n", ans);
	}

	return 0;
}