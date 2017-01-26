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

int tree[400000]={0};
int A[100000]={0},n,m;

void build(int idx,int l,int r);
int query(int idx,int l,int r,int i,int j);
void upd(int idx,int l,int r,int i,int val);

int B[100000],C[100000];
int par[100000];

map<int,vector<int> > M;

int main() {
	inp(n);
	inp(m);

	for(int i=0;i<n;i++) {
		inp(B[i]);
		M[B[i]].push_back(i);
	}

	build(1,0,n-1);
	memset(par,-1,sizeof par);
	map<int,int> s1;
	for(int i=0;i<m;i++) {
		inp(C[i]);
		s1[C[i]]++;
	}
	int ans=0;
	for(int i=0;i<m;i++) {
		// inp(C[i]);
		if(M.find(C[i])==M.end())
			continue;
		vector<int> v=M[C[i]];
		if(v.size()>=500 && s1[C[i]]>=500) {
			for(int j=0;j<500;j++)
				printf("%d ",C[i]);
			printf("\n");
			return 0;
		}

		for(int j=v.size()-1;j>=0;j--) {
			// cout<<i<<" "<<v[j]<<endl;
			if(v[j]==0) {
				upd(1,0,n-1,0,1);
					// ans=v[j];
			}
			else {
				int idx=query(1,0,n-1,0,v[j]-1);
				// cout<<A[v[j]]<<" wht "<<A[idx]<<endl;
				if(A[v[j]]<(A[idx]+1)) {
					// A[v[j]]=A[idx]+1;
					if(A[idx]!=0)
						par[v[j]]=idx;
					// cout<<"------\n";
					// cout<<v[j]<<" "<<idx<<endl;
					// cout<<A[v[j]]<<" "<<A[idx]<<endl;
					// cout<<v[j]<<"par "<<par[v[j]]<<endl;
					upd(1,0,n-1,v[j],A[idx]+1);
				}
			}
			if(A[v[j]]>A[ans]) {
				// cout<<"ans "<<v[j]<<endl;
				ans=v[j];
			}
		}

		// for(int i=0;i<n;i++)
		// 	printf("%d ",A[i] );
		// printf("\n");
		// for(int i=0;i<n;i++)
		// 	printf("%d ",B[i] );

		// printf("\n");
	}

	vector<int> v1;
	int wow=ans;
	if(A[ans]==0)
		return 0;
	while(ans!=-1) {
		v1.push_back(ans);
		// cout<<ans<<" "<<B[ans]<<endl;
		ans=par[ans];
	}

	int cnt=0;
	int sz=min(500,A[wow]);
	for(int i=sz-1;i>=0;i--) {
		printf("%d ",B[v1[i]] );
		cnt++;
		if(cnt>=sz)
			break;
	}
	printf("\n");
	return 0;
}

void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx]=l;
		A[l]=0;
		return;
	}
	int mid=(l+r)/2;
	build(2*idx,l,mid);
	build(2*idx+1,mid+1,r);
	tree[idx]=l;
}

int query(int idx,int l,int r,int i,int j) {
	if(i>j) {
		return -1; 
	}
	if(l==i && r==j) {
		return tree[idx];
	}

	int mid=(l+r)/2;

	int p1=query(2*idx,l,mid,i,min(mid,j));
	int p2=query(2*idx+1,mid+1,r,max(i,mid+1),j);

	if(p1==-1)
		return p2;
	if(p2==-1)
		return p1;
	if(A[p1]>=A[p2])
		return p1;
	else
		return p2;
}

void upd(int idx,int l,int r,int i,int val) {
	// cout<<l<<" "<<r<<" "<<i<<" "<<val<<endl;
	if(l==r) {
		// cout<<idx<<"man "<<A[idx]<<" "<<val<<endl;
		A[l]=val;
		// cout<<idx<<"man "<<A[idx]<<" "<<val<<endl;
		return;
	}

	int mid=(l+r)/2;

	if(i<=mid) {
		upd(2*idx,l,mid,i,val);
	}
	else {
		upd(2*idx+1,mid+1,r,i,val);
	}
	int p1=tree[2*idx];
	int p2=tree[2*idx+1];

	if(A[p1]>=A[p2])
		tree[idx]=p1;
	else
		tree[idx]=p2;
}