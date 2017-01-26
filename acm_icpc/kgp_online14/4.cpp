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
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,P[100001];
int tree[2000001];
int ans[100001];


void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx]=l;
		return;
	}

	int m=(l+r)/2;

	build(2*idx,l,m);
	build(2*idx+1,m+1,r);

	tree[idx]=l;
}

int query(int idx,int l,int r,int i,int j) {
	if(i>j)
		return inf;

	if(l==i && r==j)
		return tree[idx];

	int m=(l+r)/2;

	return min(query(2*idx,l,m,i,min(j,m)),
		query(2*idx+1,m+1,r,max(i,m+1),r));
}

void upd(int idx,int l,int r,int i) {

	if(i<l || r<i)
		return ;

	if(l==r) {
		tree[idx]=inf;
		return;
	}

	int m=(l+r)/2;
	upd(2*idx,l,m,i);
	upd(2*idx+1,m+1,r,i);

	tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(int i=1;i<=n;i++)
			inp(P[i]);

		build(1,1,5*n);
		upd(1,1,5*n,5*n);
		upd(1,1,5*n,5*n-1);
		
		for(int i=n;i>0;i--) {
			int q=query(1,1,5*n,P[i],5*n);
			if(q==inf) {
				q=query(1,1,5*n,1,5*n);
			}

			vector<int> v;
			v.push_back(q);
			v.push_back(q+1);
			v.push_back(q+2);

			if(q>1)
				v.push_back(q-1);
			if(q>2)
				v.push_back(q-2);

			ans[i]=q;

			for(int i=0;i<v.size();i++)
				upd(1,1,5*n,v[i]);
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i] );
		printf("\n");

	}

	return 0;
}