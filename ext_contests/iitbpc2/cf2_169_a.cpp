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

int main() {
	int ans=-inf;

	int n,k,t,f;

	cin>>n>>k;

	while(n--) {
		cin>>f>>t;
		if(t>k)
			ans=max(ans,f-t+k);
		else
			ans=max(ans,f);
	}

	printf("%d\n", ans);

	return 0;
}