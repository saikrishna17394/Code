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
#define lim 1000010
using namespace std;

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli A[lim],tree[lim],n,q,a,b,cum[lim];
char ch;
void update(lli idx,lli val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

lli sum(lli idx) {
	lli ret=0;
	while(idx) {
		ret+=tree[idx];
		idx-=(idx&-idx);
	}
	return ret;
}
int main() {
	inp(n);
	inp(q);

	for(int i=1;i<=n;i++)
		inp(A[i]);

	tree[0]=0;
	cum[0]=0;

	for(int i=1;i<=n;i++) {
		cum[i]=cum[i-1]+A[i];
		tree[i]=cum[i]-cum[i-(i&-i)];
	}

	while(q--) {
		cin>>ch;
		if(ch=='G') {
			inp(a);
			inp(b);
			update(a+1,b);
		}
		else if(ch=='T') {
			inp(a);
			inp(b);
			update(a+1,-b);
		}
		else {
			inp(a);
			inp(b);
			printf("%lld\n", sum(b+1)-sum(a));
		}
	}
	return 0;
}