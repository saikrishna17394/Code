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

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

struct node {
	int min,lazy;
};

int A[200000],ans[200000],t,n,val,pos;
node tree[800000];

void build_tree(int idx,int i,int j) {
	if(i==j) {
		tree[idx].min=A[i];
		tree[idx].lazy=0;
		return;
	}
	int mid=(i+j)/2;

	build_tree(2*idx,i,mid);
	build_tree(2*idx+1,mid+1,j);

	tree[idx].min=min(tree[2*idx].min,tree[2*idx+1].min);
	tree[idx].lazy=0;
}

void query(int idx,int l,int r) {
	if(l==r) {
		ans[l]=val;
		tree[idx].lazy=0;
		tree[idx].min=inf;
		pos=l;
		return ;
	}

	if(tree[idx].lazy>0) {
		tree[2*idx].lazy+=tree[idx].lazy;
		tree[2*idx+1].lazy+=tree[idx].lazy;
		tree[idx].lazy=0;
	}

	int a,b,mid;
	mid=(l+r)/2;

	a=tree[2*idx].min-tree[2*idx].lazy;

	b=tree[2*idx+1].min-tree[2*idx+1].lazy;

	if(a<b) {
		query(2*idx,l,mid);
		tree[idx].min=min(tree[2*idx].min,b);
	}
	else {
		query(2*idx+1,mid+1,r);
		tree[idx].min=min(a,tree[2*idx+1].min);
	}
	// cout<<idx<<" "<<tree[idx].min<<" "<<tree[idx].lazy<<endl;
}

void update(int idx,int l,int r,int i,int j) {
	if(tree[idx].min==inf)
	return;

	if(tree[idx].lazy>0) {
		if(l<r) {
			tree[2*idx].lazy+=tree[idx].lazy;
			tree[2*idx+1].lazy+=tree[idx].lazy;
		}
		tree[idx].min-=tree[idx].lazy;
		tree[idx].lazy=0;
	}

	if(i>j)
		return;



	if(i==l && r==j) {
		tree[idx].min--;
		if(l<r) {
			tree[2*idx].lazy++;
			tree[2*idx+1].lazy++;
		}
		return;
	}


	int mid=(l+r)/2;

	update(2*idx,l,mid,i,min(j,mid));
	update(2*idx+1,mid+1,r,max(i,mid+1),j);

	tree[idx].min=min(tree[2*idx].min,tree[2*idx+1].min);
}

int main() {
	inp(t);

	while(t--) {
		inp(n);

		for (int i = 0; i < n; ++i) {
			inp(A[i]);
		}
		build_tree(1,0,n-1);


		val=n;
		for(int i=0;i<n;i++) {
			query(1,0,n-1);
			//pos is updated in above query function
			update(1,0,n-1,pos+1,n-1);
			val--;
		}

		for (int i = 0; i < n; ++i)
			printf("%d ", ans[i]);
		printf("\n");
	}

	return 0;
}