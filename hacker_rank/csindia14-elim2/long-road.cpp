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

using namespace std;


inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli A[100000],tree[400000],num,q,x,c,d;
lli lazy[400000],C[400000];
int B[400000];
int n,e;


void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx]=A[l];
		lazy[idx]=0;
		B[idx]=l;
		return;
	}
	int mid=(l+r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	tree[idx]=min(tree[2*idx],tree[2*idx+1]);
	if(tree[2*idx]<=tree[2*idx+1])
		B[idx]=B[2*idx];
	else
		B[idx]=B[2*idx+1];

	lazy[idx]=0;
	// B[idx]=B[2*idx]+B[]
}

int query(int idx,int l,int r,int i,int j) {

	if(i>j) {
		return 399999; 
	}
	tree[idx]+=lazy[idx];
	if(l!=r) {
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx+1]+=lazy[idx];
	}
	lazy[idx]=0;
	
	if(l==i && r==j) {
		return B[idx];
	}
	int mid=(l+r)/2;

	int p1=query(2*idx,l,mid,i,min(mid,j));
	int p2=query(2*idx+1,mid+1,r,max(i,mid+1),j);

	if(p1 == 399999)
		return p2;
	if(p2 == 399999)
		return p1;

	if(tree[2*idx]<=tree[2*idx+1])
		B[idx]=B[2*idx];
	else
		B[idx]=B[2*idx+1];
	return B[idx];
}


lli query1(int idx,int l,int r,int i) {
	if(i<0)
		return 0;

	tree[idx]+=lazy[idx];
	if(l!=r) {
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx+1]+=lazy[idx];
	}
	lazy[idx]=0;
	
	if(l==r) {
		return tree[idx];
	}
	int mid=(l+r)/2;

	if(i<=mid)
		return query1(2*idx,l,mid,i);
	else
		return query1(2*idx+1,mid+1,r,i);

}

void upd(int idx,int l,int r,int i,int j,lli val) {

	if(i>j) {
		return ; 
	}

	tree[idx]+=lazy[idx];
	if(l!=r) {
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx+1]+=lazy[idx];
	}
	lazy[idx]=0;

	if(l==i && r==j) {
		tree[idx]+=val;
		if(l!=r) {
			lazy[2*idx]+=val;
			lazy[2*idx+1]+=val;
		}
		return ;
	}

	int mid=(l+r)/2;

	upd(2*idx,l,mid,i,min(mid,j),val);
	upd(2*idx+1,mid+1,r,max(i,mid+1),j,val);


	if(tree[2*idx]<=tree[2*idx+1])
		B[idx]=B[2*idx];
	else
		B[idx]=B[2*idx+1];
	tree[idx]=min(tree[2*idx],tree[2*idx+1]);
	return ;
}

void print(){
	cout<<tree[4]<<" "<<tree[5]<<" "<<tree[3]<<" tre"<<endl;
}

int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		inp(A[i]);
	}

	for(int i=0;i<n;i++) {
		inp(num);
		C[i]=num;
		A[i]=num-A[i];
	}

	for(int i=1;i<n;i++) {
		A[i]+=A[i-1];

	}

	build(1,0,n-1);
	tree[399999]=inf;

	inp(q);

	while(q--) {
		inp(x);

		if(x==1) {
			inp(c);
			inp(d);
			upd(1,0,n-1,(int)c-1,n-1,d-C[c-1]);
			// cout<<" upd "<<c-1<<" "<<d-C[c-1]<<endl;
			C[c-1]=d;
		}
		else {
			scanf("%d",&e);
			int pos=query(1,0,n-1,e-1,n-1);
			lli val=query1(1,0,n-1,pos);
			lli val1=query1(1,0,n-1,e-2);
			// cout<<pos<<" "<<val<<" "<<val1<<" "<<e<<endl;
			// print();
			if(val>=val1)
				printf("%d\n",n+1);
			else
				printf("%d\n", pos+1);
		}
	}

	return 0;
		
}