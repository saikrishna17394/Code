#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

ii A[200];

int main(){ 
	// cin.sync_with_stdio(false);
	int n,k;
	cin>>n>>k;

	for(int i=1;i<=n;i++) {
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A+1,A+n+1);

	int val=0;
	int ans=0;

	for(int i=1;i<=n;i++) {
		if(val+A[i].first<=k) {
			val+=A[i].first;
			ans++;
		}
		else
			break;
	}

	cout<<ans<<endl;

	for(int i=1;i<=ans;i++)
		cout<<A[i].second<<" ";

	cout<<endl;
	return 0;
}