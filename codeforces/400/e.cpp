#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

int n,m;
int A[lim],tree[lim][17]={0};

void upd(int idx,int i,int val) {
	while(idx<lim) {
		tree[idx][i]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx,int i) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx][i];
		idx-=idx&-idx;
	}
	return sum;
}


lli left(int i,int j) {
	int l=0,r=i-1;

	int val=read(i-1,j);
	while(l<r) {
		int m=(l+r)/2;
		if( (val-read(m,j))==(i-m-1))
			r=m;
		else
			l=m+1;
	}
	return (lli)(i-l-1);
}

lli right(int i,int j) {
	int l=i+1,r=n+1;

	int val=read(i,j);
	while(l<r) {
		int m=(l+r)/2;
		if( (read(m,j)-val)==(m-i))
			l=m+1;
		else
			r=m;
	}
	return (lli)(l-i-1);
}

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		cin>>A[i];


	lli ans=(lli)A[1];

	int num=A[1];
	for(int j=0;j<17;j++) {
		upd(1,j,num%2);
		num/=2;
	}

	for(int i=2;i<=n;i++) {
		int mask=A[i];
		for(int j=0;j<17;j++) {
			upd(i,j,mask%2);
			if(mask%2==1) {
				ans+=(lli)(left(i,j)+1)*(lli)(1<<j);
			}
			mask/=2;
		}
	}

	int a,b;
	while(m--) {
		int idx,num;
		cin>>idx>>num;
		int mask=num;

		// cout<<idx<<" : \n";
		for(int j=0;j<17;j++) {
			// cout<<j<<" :: ";
			if(mask%2!=A[idx]%2) {
				lli val=(left(idx,j)+1)*(right(idx,j)+1);
				val*=(lli)(1<<j);

				if(mask%2==1)
					ans+=val;
				else
					ans-=val;

				// cout<<ans<<" "<<val<<endl;
			}
			// cout<<endl;
			upd(idx,j,(mask%2)-(A[idx]%2) );
			mask/=2;
			A[idx]/=2;
		}
		A[idx]=num;
		cout<<ans<<endl;
	}

	return 0;
}