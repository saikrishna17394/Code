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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli n,k;
lli A[1000];
map<lli,lli> m;

int main() {
	inp(n);
	inp(k);

	for(lli i=0;i<n;i++) {
		inp(A[i]);
		if(m.find(k-A[i])!=m.end()) {
			printf("Yes\n");
			return 0;
		}
		m[A[i]]=1;
	}
	printf("No\n");
	return 0;
}