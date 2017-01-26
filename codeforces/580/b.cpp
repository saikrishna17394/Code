#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<long long int,long long int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

lli n,d;
ii A[lim];

int main(){ 
	cin.sync_with_stdio(false);
	cin>>n>>d;

	for(int i=0;i<n;i++) {
		cin>>A[i].first>>A[i].second;
	}
	sort(A,A+n);

	lli ans=A[0].second;
	lli val=ans;

	int l=0;

	for(int i=1;i<n;i++) {
		// cout<<A[i].first<<" xx "<<A[i].second<<endl;
		while((A[i].first-A[l].first)>=d) {
			val-=A[l].second;
			l++;
		}
		// cout<<l<<endl;
		val+=A[i].second;
		// cout<<i<<" "<<val<<endl;
		ans=max(ans,val);
	}

	cout<<ans<<endl;
	return 0;
}