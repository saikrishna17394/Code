#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#define lli long long int
#define mod 1000000007
#define inf -999999999
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

int sum[65537*2],lsum[65537*2],rsum[65537*2],msum[65537*2],A[50000],n;

void build(int num,int l,int r) {
	if(l==r) {
		sum[num]=A[l];
		lsum[num]=A[l];
		rsum[num]=A[l];
		msum[num]=A[l];
		// cout<<num<<endl;
		// cout<<msum[num]<<endl;
		return;
	}

	int mid=(l+r)/2;
	build(2*num,l,mid);
	build(2*num+1,mid+1,r);

	sum[num]=sum[2*num]+sum[2*num+1];
	lsum[num]=max(lsum[2*num],sum[2*num]+lsum[2*num+1]);
	rsum[num]=max(rsum[2*num+1],sum[2*num+1]+rsum[2*num]);

	msum[num]=max(msum[2*num],msum[2*num+1]);
	msum[num]=max(msum[num],rsum[2*num]+lsum[2*num+1]);

}

pair<ii,ii> query(int num,int l,int r,int i,int j) {
	
	if(l>j || r<i)
		return make_pair(ii(inf,inf),ii(inf,0));

	if(l>=i && r<=j) {
		// cout<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<endl;
		// cout<<num<<endl;
		// cout<<msum[num]<<endl;
		return make_pair(ii(msum[num],lsum[num]),ii(rsum[num],sum[num]));
	}

	pair<ii,ii> val1,val2;
	int mid=(l+r)/2;

	val1=query(2*num,l,mid,i,j);
	val2=query(2*num+1,mid+1,r,i,j);

	int ms,ls,rs,s;

	s=(val1.second).second+(val2.second).second;
	ls=max((val1.first).second,(val1.second).second+(val2.first).second);
	rs=max((val2.second).first,(val2.second).second+(val1.second).first);

	ms=max((val1.first).first,(val2.first).first);
	ms=max(ms,(val1.second).first+(val2.first).second);

	return make_pair(ii(ms,ls),ii(rs,s));
}

void update(int num,int l,int r,int ind,int val) {
	if(l==r) {
		// cout<<l<<" "<<ind<<" "<<val<<endl;
		sum[num]=val;
		lsum[num]=val;
		rsum[num]=val;
		msum[num]=val;	
		return;
	}

	int mid=(l+r)/2;

	if(ind>mid)
		update(2*num+1,mid+1,r,ind,val);
	else
		update(2*num,l,mid,ind,val);

	sum[num]=sum[2*num]+sum[2*num+1];
	lsum[num]=max(lsum[2*num],sum[2*num]+lsum[2*num+1]);
	rsum[num]=max(rsum[2*num+1],sum[2*num+1]+rsum[2*num]);

	msum[num]=max(msum[2*num],msum[2*num+1]);
	msum[num]=max(msum[num],rsum[2*num]+lsum[2*num+1]);

}

int main() {
	inp(n);
	int q,a,b,c;
	for(int i=0;i<n;i++)
		inp(A[i]);

	build(1,0,n-1);

	inp(q);
	
	while(q--) {
		inp(c);
		inp(a);
		inp(b);
		if(c==1)
			printf("%d\n",(query(1,0,n-1,a-1,b-1).first).first);
		
		else
			update(1,0,n-1,a-1,b);
	}

	return 0;
}