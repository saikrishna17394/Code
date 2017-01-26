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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli t,n,x,a,b,q,tree[100001][2],v;

void upd(lli idx,int i,lli val) {
	while(idx<=n) {
		tree[idx][i]+=val;
		idx+=idx&-idx;
	}
}

lli query(lli idx) {
	lli ans=0,i=idx;
	while(i>0) {
		ans+=tree[i][0];
		i-=i&-i;
	}
	ans*=idx;

	while(idx>0) {
		ans+=tree[idx][1];
		idx-=idx&-idx;
	}
	return ans;
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(q);
		memset(tree,0,sizeof tree);

		while(q--) {
			inp(x);
			inp(a);
			inp(b);
			if(x==0) {
				inp(v);
				upd(a,0,v);
				upd(a,1,-v*(a-1));
				
				upd(b+1,0,-v);
				upd(b+1,1,v*b);
			}
			else {
				printf("%lld\n", query(b)-query(a-1));
			}
		}
	}

	return 0;
}