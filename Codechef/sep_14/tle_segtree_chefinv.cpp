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
vector<int> tree[524288];
lli ans=0;

void build(int l,int r,int idx) {
	if(l==r) {
		tree[idx].push_back(A[l]);
		return;
	}

	int mid=(l+r)/2;
	build(l,mid,2*idx);
	build(mid+1,r,2*idx+1);

	int a=0,b=0;
	tree[idx].resize(r-l+1);
	int cnt=0;

	int sz1=mid-l+1;
	int sz2=r-mid;

	while(1) {
		if(a==sz1) {
			if(b==sz2)
				return;
			tree[idx][cnt++]=tree[2*idx+1][b++];
			continue;
		}
		if(b==sz2) {
			tree[idx][cnt++]=tree[2*idx][a++];
			continue;
		}

		if(tree[2*idx][a]<=tree[2*idx+1][b])
			tree[idx][cnt++]=tree[2*idx][a++];
		else {
			tree[idx][cnt++]=tree[2*idx+1][b++];
			ans+=(lli)(sz1-a);
		}
	}
	return;
}

int s=0;
// 
int query(int l,int r,int i,int j,int idx,int val) {
	// cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<idx<<endl;
	s++;
	if(i>j)
		return 0;
	// cout<<"man\n";
	int ret=0;
	if(l==i && r==j) {
		int a=0,b=r-l;
		// int dud=0;
		while(a<b) {
			s++;
			// dud++;
			int mid=(a+b)/2;
			if(tree[idx][mid]<=val)
				a=mid+1;
			else
				b=mid;
		}
		if(tree[idx][a]>val)
			ret+=(r-l+1-a);

		a=0,b=r-l;
		while(a<b) {
			s++;
			// dud++;
			int mid=(a+b)/2;
			if(tree[idx][mid+1]<val)
				a=mid+1;
			else
				b=mid;
		}
		if(tree[idx][a]<val)
			ret-=(a+1);
		// cout<<i<<" wa "<<j<<" "<<dud<<endl;
		return ret;
	}
	int mid=(l+r)/2;
	ret+=query(l,mid,i,min(j,mid),2*idx,val);
	ret+=query(mid+1,r,max(mid+1,i),j,2*idx+1,val);
	return ret;
}


int main() {
	inp(n);
	inp(m);

	for(int i=0;i<n;i++)
		inp(A[i]);

	build(0,n-1,1);
	// printf("%lld\n", ans);

	int x=0;

	// m=0;
	while(m--) {
		int a,b,i,j;
		inp(a);
		inp(b);
		a--;
		b--;
		i=min(a,b);
		j=max(a,b);


		int val=query(0,n-1,i+1,j,1,A[i])-query(0,n-1,i,j-1,1,A[j]);

		// int val=query(0,n-1,i+1,j,1,A[i]);
		// // cout<<val<<endl;
		// val-=query1(0,n-1,i+1,j,1,A[i]);
		// // cout<<val<<endl;

		// val-=query(0,n-1,i,j-1,1,A[j]);
		// // cout<<val<<endl;
		// val+=query1(0,n-1,i,j-1,1,A[j]);
		
		if(A[i]<A[j])
			val--;
		else if(A[i]>A[j])
			val++;
		else
			;
		printf("%lld\n", ans+(lli)val);
	}
	return 0;
}