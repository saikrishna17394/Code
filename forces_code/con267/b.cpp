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

int n,m,k,A[1001],ans=0;

int main() {
	cin>>n>>m>>k;

	for(int i=0;i<=m;i++)
		cin>>A[i];

	for(int i=0;i<m;i++) {
		int mask1=A[i],mask2=A[m];
		int val=0;
		for(int j=0;j<n;j++) {
			if(mask1%2!=mask2%2) {
				val++;
			}
			mask1/=2;
			mask2/=2;
		}
		if(val<=k)
			ans++;
	}

	printf("%d\n", ans);
	return 0;
}