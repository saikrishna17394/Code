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

#define mod 1000000007
#define inf 1999999999
#define lim 10000000

using namespace std;

lli n,m,w,A[100001],B[100001],tree[100001],cum[100001],l,r;

lli read(int idx) {
	lli sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

void update(int idx,lli val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

int main() {
	cin>>n>>m>>w;

	l=inf;
	// cout<<inf;
	for(int i=1;i<=n;i++) {
		cin>>A[i];
		l=min(l,A[i]);
	}
	B[0]=0;
	B[1]=A[1];
	tree[0]=0;

	for(int i=2;i<=n;i++) {
		B[i]=A[i]-A[i-1];
	}

	cum[0]=0;
	cum[1]=B[1];

	for(int i=2;i<=n;i++)
		cum[i]=cum[i-1]+B[i];


	// for(int i=2;i<=n;i++) {
	// 	B[i]=B[i]-B[i-1];
	// }

	r=l+m;

	while(l<r) {
		int mid=(l+r)/2;
		mid++;
		// cout<<l<<" "<<r<<" "<<mid<<endl;

		for(int i=1;i<=n;i++) {
			tree[i]=cum[i]-cum[i-(i&-i)];
		}

		// cout<<"tree ";
		// for(int j=0;j<=n;j++) {
		// 	cout<<tree[j]<<" ";
		// } 
		// cout<<endl;

		bool ok=true;
		lli rem=m;

		for(int i=1;i<=n;i++) {
			lli val=read(i);
			// cout<<i<<" id "<<val<<endl;
			if(val>=mid)
				continue;
			if((mid-val)>rem) {
				ok=false;
				break;
			}
			// cout<<"up "<<i<<" "<<mid-val<<endl;
			update(i,mid-val);
			// cout<<"tree ";
			// for(int j=0;j<=n;j++) {
			// 	cout<<tree[j]<<" ";
			// }
			// cout<<endl;
			// cout<<"up "<<i+w<<" "<<val-mid<<endl;
			update(i+w,val-mid);
			// cout<<"tree ";
			// for(int j=0;j<=n;j++) {
			// 	cout<<tree[j]<<" ";
			// }
			// cout<<endl;
			rem-=(mid-val);
		}
		if(ok) {
			l=mid;
		}
		else {
			r=mid-1;
		} 
	}
	cout<<l<<endl;
	return 0;
}