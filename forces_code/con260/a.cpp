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
ii A[100000];

int main() {
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i].first;
		cin>>A[i].second;
	}

	sort(A,A+n);

	bool ok=false;

	for(int i=0;i<(n-1);i++) {
		if(A[i].second>A[i+1].second)
			ok=true;
	}

	if(ok)
		printf("Happy Alex\n");
	else
		printf("Poor Alex\n");

	return 0;
}