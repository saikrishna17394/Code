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

int tree[200001]={0},n,q;
void upd(int idx,int val) {
	// cout<<"upd : "<<idx<<" "<<val<<endl;
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx) {
	int ret=0;
	// cout<<"read : "<<idx;
	while(idx>0) {
		ret+=tree[idx];
		idx-=idx&-idx;
	}
	// cout<<" "<<ret<<endl;
	return ret;
}

int A[200001],idx[200001],x,a,b;

int main() {
	inp(n);
	inp(q);

	for(int i=1;i<=n;i++) {
		inp(A[i]);
		idx[A[i]]=i;
	}

	for(int i=1;i<n;i++) {
		upd(max(A[i],A[i+1]),1);
	}

	while(q--) {
		inp(x);
		if(x==1) {
			inp(a);
			inp(b);

			if(idx[a]>1) {
				upd(max(a,A[idx[a]-1]),-1);
			}
			if(idx[b]>1) {
				upd(max(b,A[idx[b]-1]),-1);
			}

			if(idx[a]<n) {
				upd(max(a,A[idx[a]+1]),-1);
			}
			if(idx[b]<n) {
				upd(max(b,A[idx[b]+1]),-1);
			}
			swap(idx[a],idx[b]);
			A[idx[a]]=a;
			A[idx[b]]=b;
			if(idx[a]>1) {
				upd(max(a,A[idx[a]-1]),1);
			}
			if(idx[b]>1) {
				upd(max(b,A[idx[b]-1]),1);
			}

			if(idx[a]<n) {
				upd(max(a,A[idx[a]+1]),1);
			}
			if(idx[b]<n) {
				upd(max(b,A[idx[b]+1]),1);
			}

		}
		else {
			inp(x);
			int ans=x-read(x);
			printf("%d\n", ans);
		}
	}

	return 0;
}