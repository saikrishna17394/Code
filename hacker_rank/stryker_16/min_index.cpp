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
#define lim 200010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,A[2000],B[2000],num;

int main() {
	
	inp(n);

	for(int i=0;i<n;i++) {
		inp(A[i]);
	}

	map<int,int> m;

	for(int i=0;i<n;i++) {
		inp(num);
		m[num]=i;
	}

	int ans = A[0];
	int val = abs(0-m[A[0]]);

	for(int i=1;i<n;i++) {
		int val1 = abs(i-m[A[i]]);

		if(val1<val) {
			val=val1;
			ans=A[i];
		}
		else if(val1==val) {
			ans=min(ans,A[i]);
		}
		else
			;
	}

	printf("%d\n", ans);
	return 0;
}