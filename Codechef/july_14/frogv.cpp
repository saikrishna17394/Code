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
	int ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

int n,p,k,a,b;
ii A[100000];

int comp[100000];

int main() {
	inp(n);
	inp(k);
	inp(p);

	for(int i=0;i<n;i++) {
		inp(A[i].first);
		A[i].second=i;
	}

	sort(A,A+n);

	int idx=0;

	comp[A[0].second]=idx;

	for(int i=1;i<n;i++) {
		if(A[i].first-A[i-1].first<=k) {
			comp[A[i].second]=idx;
		}
		else {
			comp[A[i].second]=++idx;	
		}
	}

	while(p--) {
		inp(a);
		inp(b);
		a--;
		b--;
		if(comp[a]==comp[b])
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}