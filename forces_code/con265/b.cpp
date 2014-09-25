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

const double pi = 2 * acos(0.0);

int n,A[1000],ans;

int main() {
	cin>>n;

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	ans=0;

	bool ok=false;

	for(int i=0;i<n;i++) {
		if(A[i]==0)
			continue;
		ans++;
		if(i>0 && A[i-1]==0 && ok)
			ans++;
		ok=true;
	}

	printf("%d\n", ans);
	return 0;
}