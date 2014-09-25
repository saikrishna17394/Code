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
int A[10000000],B[10000000];
int n;
lli ans;

void merge(int l,int r) {
	if(l==r)
		return;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);

	int idx=l;
	int i=l,j=mid+1;

	vector<int> v1;

	// cout<<l<<" "<<r<<endl;
	while(idx<=r) {
		if(i>mid) {
			B[idx++]=A[j++];
			continue;
		}
		if(j>r) {
			// cout<<A[i]<<" "<<A[j]<<endl;
			B[idx++]=A[i++];
			// ans++;
			continue;
		}

		if(A[i]<A[j])
			B[idx++]=A[i++];
		else {
			ans+=(mid+1-i);
			// cout<<A[i]<<" "<<A[j]<<endl;
			B[idx++]=A[j++];
		}
	}
	for(int i=l;i<=r;i++)
		A[i]=B[i];
	return;
}
int main() {
	inp(n);
	// A.resize(n);
	// B.resize(n);
	ans=0;

	for(int i=0;i<n;i++)
		inp(A[i]);
	
	merge(0,n-1);

	printf("Number of inversions are %lld\n",ans );
	// printf("%lld\n", ans);
	return 0;
}