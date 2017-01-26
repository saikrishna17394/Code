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

int n,m;
int tree[400000],dp[100000];
int A[100000],B[100000];
int par[100000];
vector<int> v[100000];

void build(int idx,int l,int r);
int query(int idx,int l,int r,int i,int j);
void upd(int idx,int l,int r,int i,int val);


int main() {
	map<int,int> s;

	inp(n);
	inp(m);
	for(int i=0;i<n;i++) {
		inp(A[i]);
		s[A[i]]=1;
	}

	for(int i=0;i<m;i++)
		inp(B[i]);

	int num=0;

	for(map<int,int>::iterator it=s.begin();it!=s.end();it++)
		it->second=num++;

	for(int i=0;i<n;i++) {
		// cout<<i<<" w "<<s[A[i]]<<endl;
		v[s[A[i]]].push_back(i);
	}

	int ans=0;
	memset(dp,0,sizeof dp);
	memset(par,-1,sizeof par);
	build(1,0,n-1);

	for(int i=0;i<m;i++) {
		if(s.find(B[i])==s.end())
			continue;

		int k=s[B[i]];
		if(v[k].size()>=500) {
			for(int j=0;j<500;j++)
				printf("%d ",B[i] );
			printf("\n");
			return 0;
		}

		for(int j=v[k].size()-1;j>=0;j--) {
			// cout<<i<<" "<<v[k][j]<<endl;
			if(v[k][j]==0)
				upd(1,0,n-1,v[k][j],1);
			else {
				int pos=query(1,0,n-1,0,v[k][j]-1);
				if(dp[v[k][j]] <(dp[pos]+1)) {
					if(dp[pos]!=0)
						par[v[k][j]]=pos;
					dp[v[k][j]]=dp[pos]+1;
					upd(1,0,n-1,v[k][j],dp[v[k][j]]);
				}
			}
			if(dp[ans]<dp[v[k][j]])
				ans=v[k][j];
		}

		// for(int i=0;i<n;i++)
		// 	printf("%d ",dp[i] );
		// printf("\n");

	}
	vector<int> ret;

	// cout<<sz<<endl;
	int kri=dp[ans];
	int x=0;
	while(ans!=-1) {
		ret.push_back(ans);
		ans=par[ans];
		x++;
		if(x>=dp[kri])
			break;
	}

	for(int i=ret.size()-1;i>=0;i--) {
		printf("%d ",ret[i] );
		x++;
		if(x>=500)
			break;
	}
	printf("\n");
	return 0;
}



void build(int idx,int l,int r) {
	if(l==r) {
		tree[idx]=l;
		dp[l]=0;
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

	if(dp[p1]>=dp[p2])
		return p1;
	else
		return p2;
}

void upd(int idx,int l,int r,int i,int val) {

	if(l==r) {
		tree[idx]=l;
		dp[l]=val;
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

	if(dp[p1]>=dp[p2])
		tree[idx]=p1;
	else
		tree[idx]=p2;
	return;
}