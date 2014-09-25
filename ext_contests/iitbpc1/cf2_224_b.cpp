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

int n,A[200000],t,c,ans;

int main() {
	cin>>n>>t>>c;

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
	}

	ans=0;
	map<int,int> m;
	for(int i=0;i<c;i++) {
		m[A[i]]++;
	}

	if(m.rbegin()->first<=t)
		ans++;

	for(int i=c;i<n;i++) {
		m[A[i]]++;

		if(m[A[i-c]]==1) {
			m.erase(A[i-c]);
		}
		else {
			m[A[i-c]]--;
		}
		if(m.rbegin()->first<=t)
			ans++;		
	}
	printf("%d\n", ans);
	return 0;
}