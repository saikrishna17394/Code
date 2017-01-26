#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<long long int,long long int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


ii p1,p2;
lli n;
lli A[300][3];

lli solve(lli i,ii p) {
	lli ret=A[i][0]*p.first+A[i][1]*p.second+A[i][2];
	return ret;
}

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>p1.first>>p1.second;
	cin>>p2.first>>p2.second;

	cin>>n;

	int ans=0;

	for(lli i=0;i<n;i++) {
		for(int j=0;j<3;j++)
			cin>>A[i][j];

		lli val=solve(i,p1);
		lli val1=solve(i,p2);

		if((val>0 && val1>0) || (val<0 && val1<0))
			;
		else
			ans++;
	}
	cout<<ans<<endl;

	return 0;
}