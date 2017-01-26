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
#define lim 10000000

using namespace std;

int A[3000],tree[3001]={0},n,ans=0;

int read(int idx) {
	int sum=0;
	while(idx>0) {
		sum+=tree[idx];
		idx-=idx&-idx;
	}
	return sum;
}

void upd(int idx,int val) {
	while(idx<=n) {
		tree[idx]+=val;
		idx+=idx&-idx;
	}
}

int main() {
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i];

	ans=0;
	for(int i=n-1;i>=0;i--) {
		ans+=read(A[i]);
		upd(A[i],1);
	}

	// printf("%d\n", ans);
	if(ans%2==0) {
		ans*=2;
	}
	else {
		ans*=2;
		ans--;
	}
	printf("%d\n", ans);
	return 0;
}