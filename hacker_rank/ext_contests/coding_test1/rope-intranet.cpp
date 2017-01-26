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
#define inf (lli)1e16
#define lim 100001

using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int tree[10001];
int n,a,b,t;
ii A[1000];

void upd(int idx,int val) {
	while(idx<=10000) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int query(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

int main() {
	inp(t);

	for(int T=1;T<=t;T++) {
		inp(n);

		for(int i=0;i<n;i++) {
			inp(A[i].first);
			inp(A[i].second);
		}
		sort(A,A+n);

		int ans=0;
		memset(tree,0,sizeof tree);
		for(int i=n-1;i>=0;i--) {
			ans+=query(A[i].second);
			upd(A[i].second,1);
		}

		printf("Case #%d: %d\n", T,ans);
	}

	return 0;
}