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

lli n,A[300000],ans;

int main() {
	cin>>n;

	ans=0;
	lli sum=0;

	for(int i=0;i<n;i++) {
		scanf("%lld",&A[i]);
		sum+=A[i];
	}

	ans=sum;

	if(n==1) {
		printf("%lld\n", ans);
		return 0;
	} 

	ans+=sum;
	
	sort(A,A+n);

	for(int i=1;i<n;i++) {
		if(i==n-1)
			break;
		sum-=A[i-1];
		ans+=sum;
	}

	printf("%lld\n", ans);

	return 0;
}