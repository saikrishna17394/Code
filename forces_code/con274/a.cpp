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

int n;
ii A[5000];

int main() {
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i].first>>A[i].second;

	sort(A,A+n);

	// int val=A[n-1].first;

	int ans=A[n-1].first;

	bool ok=true;
	int val=A[n-1].second;
	for(int i=n-2;i>=0;i--) {
		int num=max(A[i].first,A[i].second);
		if(val>=num)
			val=num;
		else if(val>=A[i].first)
			val=A[i].first;
		else if(val>=A[i].second)
			val=A[i].second;
		else
			ok=false;
	}

	if(ok)
		ans=min(ans,A[n-1].second);
	printf("%d\n", ans);
	
	return 0;
}