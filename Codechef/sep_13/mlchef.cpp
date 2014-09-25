#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <list>
#include <vector>
#define lli long long int
#define mod 1000000007
#define inf 1999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int cnt[262144*2],color[262144*2]={0},A[100001],B[100001],health[262144*2]={0},ind=0,n;
vector<int> v[262144*2];
ii range[100001];
list<int> l1[100001];

void dfs(int i) {
	B[ind++]=i;
	int start=ind-1;

	for(list<int>::iterator it=l1[i].begin();it!=l1[i].end();it++)
		dfs(*it);
	range[i]=ii(start,ind-1);
}

void build(int num,int l,int r) {
	if(l==r) {
		cnt[num]=1;
		v[num].push_back(A[B[l]]);
		return;
	}

	int mid=(l+r)/2;

	build(2*num,l,mid);
	build(2*num+1,mid+1,r);

	int len1=mid-l+1,len2=r-mid;

	int i,j;
	for(i=0,j=0;i<len1 && j<len2;) {
		if(v[2*num][i]<=v[2*num+1][j])
			v[num].push_back(v[2*num][i++]);
		else
			v[num].push_back(v[2*num+1][j++]);
	}

	if(i==len1) {
		for(;j<len2;j++)
			v[num].push_back(v[2*num+1][j]);
	}

	else {
		for(;i<len1;i++)
			v[num].push_back(v[2*num][i]);
	}

	cnt[num]=cnt[2*num]+cnt[2*num+1];
}

int find(int num,int i,int j,int val) {
	// cout<<"finduuu "<<i<<" "<<j<<" "<<val<<endl;
	if(i==j) {
		// cout<<v[num][i]<<" "<<val<<endl;
		if(v[num][i]>val)
			return 1;
		return 0;
	}

	int mid=(i+j)/2;

	int ans=find(num,mid+1,j,val);

	if(v[num][mid]>val)
		return mid-i+1+ans;

	return ans;
}

void update(int num,int l,int r,int i,int j,int inc) {

	// cout<<num<<" "<<l<<" "<<r<<endl;
	// cout<<"sai "<<i<<" "<<j<<endl;
	if(i>j)
		return;

	if(l==i && r==j) {
		color[num]+=inc;
		// cout<<num<<" "<<color[num]<<endl;
		return;
	}

	if(color[num]!=0) {
		if(l<r) {
			color[2*num]+=color[num];
			color[2*num+1]+=color[num];
		}
		health[num]+=color[num];
		color[num]=0;
		cnt[num]=find(num,0,r-l,health[num]);
	}

	int mid=(l+r)/2;

	update(2*num,l,mid,i,min(mid,j),inc);
	update(2*num+1,mid+1,r,max(mid+1,i),j,inc);
	cnt[num]=cnt[2*num]+cnt[2*num+1];
}

int query(int num,int l,int r,int i,int j) {
	// cout<<num<<" "<<l<<" "<<r<<endl;
	// cout<<"saikri "<<i<<" "<<j<<endl;

	if(i>j)
		return 0;

	if(color[num]!=0) {
		if(l<r) {
			color[2*num]+=color[num];
			color[2*num+1]+=color[num];
		}
		health[num]+=color[num];
		color[num]=0;

		cnt[num]=find(num,0,r-l,health[num]);
	}

	if(l==i && r==j)
		return cnt[num];

	int mid=(l+r)/2;

	return query(2*num,l,mid,i,min(mid,j))+query(2*num+1,mid+1,r,max(mid+1,i),j);
}

int main() {
	int a,h,t,q,x;
	inp(n);

	A[0]=inf;	//simply doesnt matter
	for(int i=1;i<=n;i++) {
		inp(h);
		inp(a);
		A[i]=h;
		l1[a].push_back(i);
	}

	dfs(0);

	build(1,0,n);


	inp(t);

	while(t--) {
		inp(q);

		if(q==1) {
			inp(a);
			inp(x);

			// cout<<range[a].first<<" "<<range[a].second<<endl;
			if(range[a].first!=range[a].second)
				update(1,0,n,range[a].first+1,range[a].second,x);
			else
				;

		}
		else {
			inp(a);

			if(range[a].first!=range[a].second)
				printf("%d\n",query(1,0,n,range[a].first+1,range[a].second));
			else
				printf("0\n");
		}
	}

	return 0;
}