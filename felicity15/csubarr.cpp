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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16
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

lli n;
lli A[lim];
lli k,idx;
lli tree[lim];

void upd(lli x,lli val) {
	while(x<=idx) {
		tree[x]+=val;
		x+=x&-x;
	}
}

lli read(lli x) {
	lli sum=0;
	while(x>0) {
		sum+=tree[x];
		x-=x&-x;
	}
	return sum;
}

int main() {
	inp(n);
	inp(k);

	map<lli,lli> m;

	for(lli i=1;i<=n;i++) {
		inp(A[i]);
		m[A[i]]=0;
	}

	if(k==0) {
		printf("%lld\n", (n*(n+1))/2);
		return 0;
	}

	idx=1;

	for(map<lli,lli>::iterator it=m.begin();it!=m.end();it++) {
		it->second=idx++;
	}

	for(lli i=1;i<=n;i++)
		A[i]=m[A[i]];

	memset(tree,0,sizeof tree);

	lli ans=0;
	upd(A[1],1);

	lli cur=0;
	lli l=1;

	for(lli i=2;i<=n;i++) {
		lli val=read(idx)-read(A[i]);

		// cout<<i<<" "<<cur<<" "<<val<<" : "<<endl;

		while((cur+val)>=k) {
			cur-=read(A[l]-1);
			upd(A[l],-1);

			// cout<<cur<<" --- "<<l<<endl;
			l++;
			val=read(idx)-read(A[i]);
		}
		cur+=val;

		// cout<<i<<" "<<l<<endl;
		ans+=(l-1);
		upd(A[i],1);
	}
	printf("%lld\n", ans);
	return 0;
}