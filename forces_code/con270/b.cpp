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


int n,k,A[2000];

int main() {
	cin>>n>>k;

	for(int i=0;i<n;i++) {
		cin>>A[i];
		A[i]--;
	}

	sort(A,A+n);

	int ans=0;

	int i=n-1;
	for(;i>=0;i-=k) {
		ans+=2*A[i];
	}

	printf("%d\n", ans);

	return 0;
}