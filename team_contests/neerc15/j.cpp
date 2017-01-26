#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<long long int,long long int> ii;

using namespace std;

lli n,t;
lli p[50010],d[50010],dp[50010];
ii A[50010];
lli big[50010];

ii st[50010];

int main(){ 
	freopen("journey.in", "r", stdin);
	// freopen("inp", "r", stdin);
	freopen("journey.out", "w", stdout);

	cin>>n>>t;


	t-=(n-1);

	for(lli i=0;i<(n-1);i++) {
		cin>>A[i].first;
		A[i].second=i+1;
	}

	sort(A,A+n-1);

	big[0]=A[0].second;
	for(lli i=1;i<(n-1);i++) {
		big[i]=max(big[i-1],A[i].second);
	}


	for(int i=2;i<n;i++)
		cin>>d[i];
	d[n]=0;

	lli l=0,r=n-2;

	while(l<r) {
		lli m=(l+r)/2;

		lli price=A[m].first;
		lli gap=big[m];

		// cout<<l<<" "<<r<<" : \n";
		// cout<<price<<" "<<gap<<endl;

		int sz=0,idx=0;

		for(lli i=2;i<=(gap+1);i++) {
			dp[i]=d[i];
		}

		st[sz++]=ii(dp[2],2);

		for(lli i=3;i<=(gap+1);i++) {
			while(idx<sz && st[sz-1].first>=dp[i]) {
				sz--;
			}
			st[sz++]=ii(dp[i],i);
		}

		for(lli i=gap+2;i<=n;i++) {
			dp[i]=d[i]+st[idx].first;

			while(idx<sz && st[sz-1].first>=dp[i])
				sz--;
			st[sz++]=ii(dp[i],i);

			if(st[idx].second==(i-gap))
				idx++;
		}


		// cout<<dp[n]<<endl;
		if(dp[n]<=t)
			r=m;
		else
			l=m+1;
	}

	cout<<A[l].first<<endl;
	return 0;
}