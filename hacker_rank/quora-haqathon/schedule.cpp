#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,double>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int n;
ii A[100];
pair<double,int> B[100];

int main() {
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i].first>>A[i].second;
		B[i].second=i;
		B[i].first=A[i].second;
	}

	sort(B,B+n);

	double val=1;
	double ans=0;
	int tim=0;

	for(int j=0;j<n;j++) {
		int i=B[j].second;
		// cout<<i<<" "<<B[j].first<<" "<<B[j].second<<endl;
		tim+=A[i].first;
		ans+=(double)tim*(val*(1.0	-A[i].second));
		// cout<<ans<<" : "<<tim<<" "<<val*(1.0 - A[i].second)<<endl;
		val*=A[i].second;
	}
	ans+=(double)tim*val;
	// cout<<ans<<" "<<tim<<" "<<val<<endl;
	printf("%.9f\n", ans);
	return 0;
}