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

inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
lli tree[200001]={0},A[200001],ans[200001],n,b,q,num;

void update(lli x,lli val) {
	while(x<=n) {
		tree[x]+=val;
		x+=x&-x;
	}
}

lli sum(lli x) {
	lli ret=0;
	while(x) {
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}


int main() {
	inp(n);
	inp(b);

	for(int i=1;i<=n;i++)
		inp(A[i]);

	ans[b]=1;
	update(b,1);

	for(lli i=b-1;i>=1;i--) {
		ans[i]=sum(min(i+A[i],b));
		ans[i]%=mod;
		update(i,ans[i]);
	}
	inp(q);
	while(q--) {
		inp(num);
		printf("%lld\n", ans[num]);
	}
	return 0;
}