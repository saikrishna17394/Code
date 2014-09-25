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

// ******************************************************************
// I could have done this implementation better
// Which I wiil do it from now whenever I use a segment tree
// Mnay If statements could be optimized
// ******************************************************************

const int LIM=(1<<18);
int tree[LIM][3]={0},lazy[LIM]={0};

void build (int idx,int l,int r) {
	if(l==r) {
		tree[idx][0]=1;
		return;
	}
	int mid=(l+r)/2;

	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	tree[idx][0]=r-l+1;
}

void update(int idx,int l,int r,int i,int j) {
	int temp;
	lazy[idx]%=3;

	if(l==i && r==j)	// add only when the interval is totaly contained
		lazy[idx]=(lazy[idx]+1)%3;

	// cout<<idx<<" "<<lazy[idx]<<endl;
	if(lazy[idx]==1) {
		temp=tree[idx][2];

		tree[idx][2]=tree[idx][1];
		tree[idx][1]=tree[idx][0];
		tree[idx][0]=temp;
	}
	else if(lazy[idx]==2) {
		temp=tree[idx][2];

		tree[idx][2]=tree[idx][0];
		tree[idx][0]=tree[idx][1];
		tree[idx][1]=temp;
	}
	else
		;

	if(l<r) {	// **************************************************
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx+1]+=lazy[idx];
	}
	lazy[idx]=0;

	if(i>j)		//Interval doesn't interesect still had to update the lazy one 
		return;

	if(i==l && r==j) {	//Interval totaly contained so lazy propagate the children
						//and return
		// Children ni kuda paine lazy propogate chesesa paina ne
		// '*' s unna chota chudu

		return;
	}

	// Interval partly contained still updated lazy and update childs and then update
	int mid=(l+r)/2;

	update(2*idx,l,mid,i,min(j,mid));
	update(2*idx+1,mid+1,r,max(i,mid+1),j);

	for(int a=0;a<3;a++)
		tree[idx][a]=tree[2*idx][a]+tree[2*idx+1][a];
}

int query(int idx,int l,int r,int i,int j) {
	if(i>j)
		return 0;
	
	int temp;
	lazy[idx]%=3;

	if(lazy[idx]==1) {
		temp=tree[idx][2];

		tree[idx][2]=tree[idx][1];
		tree[idx][1]=tree[idx][0];
		tree[idx][0]=temp;
	}
	else if(lazy[idx]==2) {
		temp=tree[idx][2];

		tree[idx][2]=tree[idx][0];
		tree[idx][0]=tree[idx][1];
		tree[idx][1]=temp;
	}
	else
		;

	if(l<r) {	
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx+1]+=lazy[idx];
	}
	lazy[idx]=0;

	if(l==i && r==j)
		return tree[idx][0];

	int ans,mid=(l+r)/2;
	ans=query(2*idx,l,mid,i,min(j,mid));
	ans+=query(2*idx+1,mid+1,r,max(i,mid+1),j);

	return ans;
}
int main() {
	int n,q,a,b,c;

	inp(n);
	build(1,0,n-1);

	inp(q);

	while(q--) {
		inp(c);
		inp(a);
		inp(b);

		if(c) {
			printf("%d\n", query(1,0,n-1,a,b));
		}
		else {
			update(1,0,n-1,a,b);
		}

	}

	return 0;
}