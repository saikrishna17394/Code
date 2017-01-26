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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf 999999999
#define lim 1000010

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int n;
int A[lim],B[lim];
int q,t;
vector<int> tree[4*lim];

void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx].push_back(B[l]);
		return;
	}
	int m=(l+r)/2;
	build(2*idx,l,m);
	build(2*idx+1,m+1,r);

	int a=0,b=0;

	while(1) {
		if(a==tree[2*idx].size()) {
			if(b==tree[2*idx+1].size())
				break;
			tree[idx].push_back(tree[2*idx+1][b++]);
		}
		else if(b==tree[2*idx+1].size())
			tree[idx].push_back(tree[2*idx][a++]);
		else {
			if(tree[2*idx][a]<=tree[2*idx+1][b])
				tree[idx].push_back(tree[2*idx][a++]);
			else
				tree[idx].push_back(tree[2*idx+1][b++]);
		}
	}
}

int solve(vector<int> & v,int val) {
	int l=0,r=v.size()-1;

	while(l<r) {
		int m=(l+r)/2;
		if(v[m+1]>=val)
			r=m;
		else
			l=m+1;
	}
	if(v[l]<val)
		return l+1;
	return 0;
}

int query(int idx,int l,int r,int i,int j,int val) {
	// cout<<idx<<" : "<<l<<" "<<r<<" ";
	// cout<<i<<"  "<<j<<" -------- \n";
	// return 0;
	if(i>j) {
		// printf("0\n");
		return 0;
	}

	if(l==i && r==j) {
		int ret=solve(tree[idx],val);
		// printf("%d\n",ret );
		return ret;
	}
	int m=(l+r)/2;

	int ret=query(2*idx,l,m,i,min(m,j),val)+
			query(2*idx+1,m+1,r,max(m+1,i),j,val);
	
	// cout<<idx<<" : "<<l<<" "<<r<<" ";
	// cout<<i<<" : "<<j<<" -------- ";

	// printf("%d\n", ret);
	return ret;
	// return query(2*idx,l,m,i,min(m,j),val)+
	// 		query(2*idx+1,m+1,r,max(m+1,i),j,val);
}

int main() {
	inp(n);

	map<int,int> m;

	for(int i=1;i<=n;i++) {
		inp(A[i]);
		if(m.find(A[i])==m.end()) {
			B[i]=0;
			m[A[i]]=i;
		}
		else {
			B[i]=m[A[i]];
			m[A[i]]=i;
		}
	}

	build(1,1,n);

	inp(t);

	int x,r;
	int ans=0;
	while(t--) {
		inp(x);
		inp(r);
		int l=ans+x;
		ans=query(1,1,n,l,r,l);
		printf("%d\n", ans);
	}

	return 0;
}