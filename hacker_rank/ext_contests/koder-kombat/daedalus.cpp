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


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int tree[400000];
int n,a,b,m,q,num;
int B[100001]={0};

void upd(int idx,int l,int r,int i,int val) {
	if(l==r) {
		if(B[val]==0)
			tree[idx]=val;
		else
			tree[idx]=-1;
		return;
	}

	int mid=(l+r)/2;

	if(i<=mid)
		upd(2*idx,l,mid,i,val);
	else
		upd(2*idx+1,mid+1,r,i,val);

	tree[idx]=max(tree[2*idx],tree[2*idx+1]);
}

int query(int idx,int l,int r,int i,int j) {
	if(i>j)
		return -1;

	if(l==i && r==j)
		return tree[idx];

	int mid=(l+r)/2;
	return max(query(2*idx,l,mid,i,min(j,mid)),
		query(2*idx+1,mid+1,r,max(i,mid+1),j));
}

int main() {
	inp(n);
	inp(m);

	B[0]=B[1]=1;
	for(int i=2;i*i<=(100000);i++) {
		if(B[i]==0) {
			for(int j=i*i;j<100001;j+=i)
				B[j]=1;
		}
	}

	memset(tree,-1,sizeof tree);

	for(int i=0;i<n;i++) {
		inp(num);
		upd(1,0,n-1,i,num);
	}

	while(m--) {
		inp(q);
		inp(a);
		inp(b);


		if(q==1) {
			a--;
			b--;
			printf("%d\n", query(1,0,n-1,a,b));
		}
		else {
			a--;
			upd(1,0,n-1,a,b);
		}
	}

	return 0;
}