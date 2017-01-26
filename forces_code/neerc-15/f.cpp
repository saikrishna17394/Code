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

int A[200000],n,k,B[200000];

int main() {
	cin>>n>>k;

	k=min(n,k);
	int sum=0;
	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		if(i<k)
			sum+=A[i];
	}


	if(2*k>=n) {
		printf("%d\n", sum);
		return 0;
	}

	B[0]=sum;
	multiset<int> s;
	for(int i=1;(i+k)<=n;i++) {
		B[i]=B[i-1]+A[i+k-1]-A[i-1];
		if(i>=k)
			s.insert(B[i]);
	}
	int ans=0;

	for(int i=0;(i+k)<n;i++) {
		if(s.empty())
			break;
		int val=*s.rbegin();
		ans=max(ans,B[i]+val);
		s.erase(s.find(B[i+k]));
	}
	printf("%d\n", ans);
	return 0;
}