#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<long long int,long long int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


lli n,r,avg;
ii A[100000];

int main(){ 
	cin.sync_with_stdio(false);
	
	cin>>n>>r>>avg;
	lli sum=0;

	for(lli i=0;i<n;i++) {
		cin>>A[i].second>>A[i].first;
		sum+=A[i].second;
	}

	lli ans=0;
	lli rem=avg*n-sum;

	sort(A,A+n);

	for(lli i=0;i<n;i++) {
		if(rem>0) {
			ans+=min(rem,r-A[i].second)*A[i].first;
			rem-=(r-A[i].second);
		}
	}
	cout<<ans<<endl;
	return 0;
}