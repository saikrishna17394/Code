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

#define mod 5000000
#define inf 999999999
#define lim 100001
#define LN 18
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

struct node{
	node *left,*right;
	int count;

	node(int count,node *left,node *right):
		count(count),left(left),right(right){}
	node* insert(int l,int r,int w);
};

node* node::insert(int l,int r,int w) {
	if(l<=w && w<=r) {
		if(l==r)
			return new node(count+1,NULL,NULL);

		int m=(l+r)/2;
		return new node(count+1,left->insert(l,m,w),right->insert(m+1,r,w));
	}
	return this;
}

node* null=new node(0,NULL,NULL);

int n,A[lim],B[lim],idx,q;
node* root[lim];

int query(node* a,node* b,int l,int r,int k) {
	if(l==r)
		return l;

	int count=b->left->count - a->left->count;

	int m=(l+r)/2;
	if(k>count)
		return query(a->right,b->right,m+1,r,k-count);

	return query(a->left,b->left,l,m,k);
}

int main() {
	null->left=null;
	null->right=null;

	inp(n);
	inp(q);

	map<int,int> m;
	for(int i=0;i<n;i++) {
		inp(A[i]);
		m[A[i]]=1;
	}

	idx=0;

	for(map<int,int>::iterator it=m.begin();it!=m.end();it++) {
		it->second=idx;
		B[idx]=it->first;
		idx++;
	}

	root[0]=null->insert(0,idx-1,m[A[0]]);

	
	for(int i=1;i<n;i++) {
		root[i]=root[i-1]->insert(0,idx-1,m[A[i]]);
	}
	
	int i,j,k;
	while(q--) {
		inp(i);
		inp(j);
		inp(k);
		i--;
		j--;

		node *a,*b;
		if(i!=0)
			a=root[i-1];
		else
			a=null;
		b=root[j];

		int ans=query(a,b,0,idx-1,k);
		printf("%d\n", B[ans]);
	}
	return 0;
}