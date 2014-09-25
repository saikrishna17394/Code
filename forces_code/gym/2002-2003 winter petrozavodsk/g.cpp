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
ii A[200000],v[200000];
map<ii,int> m;

bool cmp(ii a,ii b) {
	if(a.first!=b.first)
		return a.first<b.first;
	return a.second>b.second;
}

int par[200001];

int main() {
	freopen("people.in", "r", stdin);
	freopen("people.out", "w", stdout);

	scanf("%d",&n);

	for(int i=0;i<n;i++) {
		scanf("%d %d",&A[i].first,&A[i].second);
		m[A[i]]=i+1;
	}

	sort(A,A+n,cmp);

	int ans=1;
	v[0]=A[0];
	memset(par,-1,sizeof par);
	par[m[A[0]]]=-1;

	for(int i=1;i<n;i++) {
		// cout<<i<<" "<<A[i].first<<" "<<A[i].second<<endl;
		int l=0,r=ans-1;

		while(l<r) {
			int mid=(l+r)/2;
			if(A[i].second<=v[mid].second)
				r=mid;
			else
				l=mid+1;

		}

		if(A[i].second>v[l].second) {
			v[ans]=A[i];
			par[m[A[i]]]=m[v[l]];
			ans++;
		}
		else {
			par[m[A[i]]]=l ? m[v[l-1]]:-1;
			v[l]=A[i];
		}
	}

	printf("%d\n", ans);

	int idx=m[v[ans-1]];

	while(1) {
		printf("%d ",idx );
		if(par[idx]==-1)
			break;
		idx=par[idx];
	}
	printf("\n");

	return 0;
}