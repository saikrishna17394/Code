#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int main(){ 
	lli t,n;

	cin>>t;

	while(t--) {
		cin>>n;

		lli val=(n*(n+1))/2;

		for(lli i=0;i<n;i++) {
			lli a,b;
			scanf("%lld %lld",&a,&b);
			val-=b;
		}
		cout<<val<<endl;
	}

	return 0;
}