#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 200010

using namespace std;

int n;
int tree[lim];
int A[lim],B[lim];
int cnt[lim];

void upd(int idx,int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int read(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

int main(){ 
	cin.sync_with_stdio(false);
	
	cin>>n;

	memset(tree,0,sizeof tree);
	for(int i=0;i<n;i++)
		upd(i+1,1);

	for(int i=0;i<n;i++) {
		cin>>A[i];
		cnt[n-i-1]=read(A[i]);
		upd(A[i]+1,-1);
	}

	for(int i=0;i<n;i++)
		upd(i+1,1);

	for(int i=0;i<n;i++) {
		cin>>B[i];
		cnt[n-i-1]+=read(B[i]);
		upd(B[i]+1,-1);
		// cout<<n-1-i<<" "<<cnt[i]<<endl;;
	}

	// cout<<"bro\n";

	for(int i=0;i<n;i++) {
		if(cnt[i]>i) {
			cnt[i+1]++;
			cnt[i]-=(i+1);
		}
		// cout<<cnt[i]<<" ";
	}
	// cout<<endl;

	memset(tree,0,sizeof tree);

	for(int i=0;i<n;i++)
		upd(i+1,1);

	for(int i=n-1;i>=0;i--) {

		int l=1,r=n;

		while(l<r) {
			int m=(l+r)/2;
			if(read(m)>=(cnt[i]+1))
				r=m;
			else
				l=m+1;
		}
		cout<<l-1;
		if(i!=0)
			cout<<" ";
		upd(l,-1);

	}
	cout<<endl;
	return 0;
}