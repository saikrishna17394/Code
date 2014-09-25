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
#include <iomanip>
#define lli long long int
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n,m,A[200000];
vector<int> tree[800000];
lli ans=0;

void build(int l,int r,int idx) {
	tree[idx].clear();
	if(l==r) {
		tree[idx].push_back(A[l]);
		return;
	}

	int mid=(l+r)/2;
	build(l,mid,2*idx);
	build(mid+1,r,2*idx+1);

	int a=0,b=0;

	while(1) {
		if(a==tree[2*idx].size()) {
			if(b==tree[2*idx+1].size())
				return;
			tree[idx].push_back(tree[2*idx+1][b++]);
			continue;
		}
		if(b==tree[2*idx+1].size()) {
			tree[idx].push_back(tree[2*idx][a++]);
			continue;
		}

		if(tree[2*idx][a]<=tree[2*idx+1][b])
			tree[idx].push_back(tree[2*idx][a++]);
		else {
			tree[idx].push_back(tree[2*idx+1][b++]);
			ans+=(lli)(tree[2*idx].size()-a);
		}
	}
	return;
}


int main() {
	inp(n);
	inp(m);

	for(int i=0;i<n;i++)
		inp(A[i]);

	// build(0,n-1,1);
	// printf("%lld\n", ans);

	while(m--) {
		int a,b,i,j;
		inp(a);
		inp(b);
		a--;
		b--;
		i=min(a,b);
		j=max(a,b);

		ans=0;
		swap(A[i],A[j]);
		build(0,n-1,1);
		swap(A[i],A[j]);
		printf("%lld\n", ans);
	}
	return 0;


}