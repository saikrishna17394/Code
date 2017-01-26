#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<long long int,long long int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


lli t,r;
lli x,y;
ii A[4];

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>t;

	while(t--) {
		scanf("%lld %lld %lld",&r,&x,&y);

		bool ok=true;
		for(int i=0;i<4;i++) {
			scanf("%lld %lld",&A[i].first,&A[i].second);

			lli val=(A[i].first-x)*(A[i].first-x);
			val+=(A[i].second-y)*(A[i].second-y);

			if(val>(r*r)) {
				ok=false;
			}
		}

		if(ok)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}