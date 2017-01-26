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
#define lim 10000000

using namespace std;

int A[1000001],n;

int tree[4000000];
lli sum[4000000],lazy[4000000];

void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx]=l;
		return ;
	}
	int m=(l+r)/2;

	build(2*idx,l,m);
	build(2*idx+1,m+1,r);

	if(A[tree[2*idx]]<=A[tree[2*idx+1]])
		tree[idx]=tree[2*idx];
	else
		tree[idx]=tree[2*idx+1];
	return;
}

int main() {
	cin.sync_with_stdio(false);

	memset(sum,0,sizeof sum);
	memset(lazy,0,sizeof lazy);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>A[i];

	build(1,1,n);

	lli ans=0;

	for(int i=2;i<=n;i++) {
		int pos=find_min(1,1,n,A[i]);
		if(pos)
	}

	cout<<ans<<endl;
	return 0;
}