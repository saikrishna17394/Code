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

#define mod 1000000009
#define inf 999999999
#define MAXN 100010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int A[MAXN],n,m,B[MAXN];
vector<int> v[MAXN],mult[MAXN],tree[MAXN];

void build(int i,int idx,int l,int r) {
	if(l==r) {
		tree[i][idx]=A[mult[i][l]];
		return;
	}
	int mid=(l+r)/2;
	build(i,2*idx,l,mid);
	build(i,2*idx+1,mid+1,r);
	tree[i][idx]=max(tree[i][2*idx],tree[i][2*idx+1]);
	return;
}

int query(int k,int idx,int l,int r,int i,int j) {
	// cout<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
	if(i>j)
		return -1;
	if(l==i && r==j) {
		// cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<tree[k][idx]<<endl;
		return tree[k][idx];
	}

	int mid=(l+r)/2;
	int val=max(query(k,2*idx,l,mid,i,min(j,mid)),query(k,2*idx+1,mid+1,r,max(i,mid+1),j));
	// cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<val<<endl;
	return val;
}

int find_max(int k,int x,int y) {
	// cout<<k<<" "<<x<<" kri "<<y<<endl;
	if(mult[k].size()==0) {
		// cout<<"yo -1\n";
		return -1;
	}

	// cout<<"man\n";

	// for(int i=0;i<mult[k].size();i++)
	// 	cout<<i<<" "<<mult[k][i]<<" "<<A[mult[k][i]]<<endl;
	// cout<<endl;

	int l=0,r=mult[k].size()-1,i,j;

	while(l<r) {
		// cout<<l<<" "<<
		int mid=(l+r)/2;

		if(mult[k][mid]>=x)
			r=mid;
		else
			l=mid+1;
	}

	if(mult[k][l]>=x)
		i=l;
	else
		i=mult[k].size();

	l=0;
	r=mult[k].size()-1;

	while(l<r) {
		int mid=(l+r)/2;

		if(mult[k][mid+1]<=y) {
			l=mid+1;
		}
		else {
			r=mid;
		}
	}

	if(mult[k][l]<=y)
		j=l;
	else
		j=-1;

	// cout<<"sai "<<i<<" "<<j<<endl;
	// // cout<<"yo "<<query(k,0,0,mult[k].size()-1,i,j)<<endl;
	return query(k,1,0,mult[k].size()-1,i,j);
}
int main() {
	inp(n);
	inp(m);

	memset(B,0,sizeof B);

	for(int i=2;(i*i)<MAXN;i++) {
		if(B[i]==0) {
			for(int j=i*i;j<MAXN;j+=i) {
				B[j]=i;
			}
		}
	}

	int num;

	for(int i=1;i<=n;i++) {
		inp(A[i]);
		v[A[i]].push_back(i);
		num=A[i];

		while(num>1) {
			if(B[num]==0) {
				mult[num].push_back(i);
				num=1;
			}
			else {
				int x=B[num];
				mult[x].push_back(i);
				while(num%x==0)
					num/=x;
			}
		}
	}

	for(int i=1;i<MAXN;i++) {
		if(mult[i].size()) {
			n=mult[i].size();
			tree[i].resize(4*n);
			build(i,1,0,n-1);
		}
	}

	int g,x,y;

	while(m--) {
		inp(g);
		inp(x);
		inp(y);

		int ans=-1;

		while(g>1) {
			if(B[g]==0) {
				ans=max(ans,find_max(g,x,y));
				g=1;
			}
			else {
				int k=B[g];
				ans=max(ans,find_max(k,x,y));
				while(g%k==0)
					g/=k;
			}
		}


		if(ans==-1) {
			printf("-1 -1\n");
			continue;
		}

		int l=0,r=v[ans].size()-1,i,j;

		while(l<r) {
			int mid=(l+r)/2;

			if(v[ans][mid]>=x)
				r=mid;
			else
				l=mid+1;
		}
		i=l;

		l=0;
		r=v[ans].size()-1;

		while(l<r) {
			int mid=(l+r)/2;

			if(v[ans][mid+1]<=y) {
				l=mid+1;
			}
			else {
				r=mid;
			}
		}
		j=l;

		if(j>=i)
			printf("%d %d\n", ans,j-i+1);
		else
			printf("-1 -1\n");
	}

	return 0;
}