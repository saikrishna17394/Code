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

lli t,n,k,A[100010];
lli tree[100011];

void upd(lli idx,lli val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

int main() {
	inp(t);

	for(int a=1;a<=t;a++) {
		inp(n);
		inp(k);

		for(int i=0;i<n;i++)
			inp(A[i]);
		memset(tree,0,sizeof tree);
		lli ans=0;

		set<lli> s;
		for(int i=n-1;i>=0;i--) {
			ans+=(lli)read(A[i]-1);
			upd(A[i],1);
			s.insert(A[i]);
		}

		if(ans>=k) {
			ans-=(lli)k;
			printf("Case %d: %lld\n",a, ans);
		}
		else if(s.size()!=(int)n) {
			ans=0;
			printf("Case %d: %lld\n",a, ans);
		}
		else {
			ans=k-ans;
			if(ans%2==0)
				ans=0;
			else
				ans=1;
			printf("Case %d: %lld\n",a, ans);
		}
	}


	return 0;
}