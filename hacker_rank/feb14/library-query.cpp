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

int t,n,q,A[10001],cur;

vector<int> tree[40000];

void build_tree(int idx,int l,int r) {
	tree[idx].resize(r-l+1);
	if(l==r) {
		tree[idx][0]=A[l];
		return ;
	}

	int mid=(l+r)/2;
	build_tree(2*idx,l,mid);
	build_tree(2*idx+1,mid+1,r);

	int i=0,a=0,b=0;

	while(i<tree[idx].size()) {
		if(a==tree[2*idx].size()) {
			tree[idx][i++]=tree[2*idx+1][b++];
			continue;
		}
		if(b==tree[2*idx+1].size()) {
			tree[idx][i++]=tree[2*idx][a++];
			continue;
		}

		if(tree[2*idx][a]<=tree[2*idx+1][b])
			tree[idx][i++]=tree[2*idx][a++];
		else
			tree[idx][i++]=tree[2*idx+1][b++];
	}

}

int query(int idx,int l,int r,int i,int j) {
	// cout<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
	if(i>j)
		return 0;
	
	if(l==i && r==j) {
		int l1=0,r1=tree[idx].size()-1;

		while(l1<=r1) {
			// cout<<l1<<" "<<r1<<endl;
			if(l1==r1) {
				if(tree[idx][l1]>cur)
					return l1;
				else
					return l1+1;
			}
			int mid=(l1+r1)/2;
			// cout<<l1<<" "<<r1<<
			if(tree[idx][mid+1]<=cur)
				l1=mid+1;
			else
				r1=mid;
		}
	}

	int mid=(l+r)/2;
	int ret=query(2*idx,l,mid,i,min(j,mid));
	ret+=query(2*idx+1,mid+1,r,max(i,mid+1),j);
	return ret;

}

void update(int idx,int l,int r,int pos,int val) {
	if(l>pos || r<pos)
		return;
	if(l==r) {
		tree[idx][0]=val;
		return;
	}
	int mid=(l+r)/2;
	update(2*idx,l,mid,pos,val);
	update(2*idx+1,mid+1,r,pos,val);
	int i=0,a=0,b=0;

	while(i<tree[idx].size()) {
		if(a==tree[2*idx].size()) {
			tree[idx][i++]=tree[2*idx+1][b++];
			continue;
		}
		if(b==tree[2*idx+1].size()) {
			tree[idx][i++]=tree[2*idx][a++];
			continue;
		}

		if(tree[2*idx][a]<=tree[2*idx+1][b])
			tree[idx][i++]=tree[2*idx][a++];
		else
			tree[idx][i++]=tree[2*idx+1][b++];
	}
	return ;	
}
// First persistent segment tree try chedam
int x,y,k,a;

int main() {
	inp(t);

	while(t--) {
		inp(n);
		for(int i=1;i<=n;i++)
			inp(A[i]);
		build_tree(1,1,n);
		inp(q);

		while(q--) {
			inp(a);

			if(a==0) {
				inp(x);
				inp(y);
				inp(k);
				// cout<<x<<" "<<y<<" "<<k<<endl;
				int l=1,r=1000;

				while(l<r) {
					int mid=(l+r)/2;
					cur=mid;
					int val=query(1,1,n,x,y);
					// cout<<mid<<" "<<val<<endl; 
					if(val>=k)
						r=mid;
					else
						l=mid+1;
				}
				printf("%d\n", l);
			}
			else {
				inp(x);
				inp(k);
				update(1,1,n,x,k);
			}
		}
	}

	return 0;
}