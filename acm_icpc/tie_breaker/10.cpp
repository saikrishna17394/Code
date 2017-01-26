#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<long long int,long long int> ii;

using namespace std;

lli t,l,n;
ii A[lim];
lli ans[lim];

int main() {
	cin>>t;

	while(t--) {
		cin>>n>>l;

		for(int i=0;i<n;i++) {
			cin>>A[i].first;
			A[i].second=i;
		}

		sort(A,A+n);

		if(A[0].first!=1) {
			printf("-1\n");
			continue;
		}

		bool ok=true;

		lli val=0;
		for(int i=1;i<n;i++) {
			if((A[i].first%A[i-1].first)!=0)
				ok=false;
			val+=A[i].first;
		}

		if((!ok) || val>l) {
			printf("-1\n");
			continue;
		}

		if(n==1) {
			cout<<l<<endl;
			continue;
		}


		ans[A[0].second]=A[1].first-1;
		lli sum=ans[A[0].second];

		for(int i=1;i<(n-1);i++) {
			ans[A[i].second]=(A[i+1].first-sum-1)/A[i].first;
			sum+=(ans[A[i].second]*A[i].first);
		}

		if(sum>=l || ( ((l-sum)%A[n-1].first)!=0) ) {
			printf("-1\n");
			continue;
		}

		ans[A[n-1].second]=(l-sum)/A[n-1].first;

		for(int i=0;i<n;i++)
			printf("%lld ", ans[i]);
		printf("\n");
	}

	return 0;
}