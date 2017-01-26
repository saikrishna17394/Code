#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int main() {
	int t,n;

	cin>>t;

	while(t--) {
		cin>>n;

		double ans=100.0;

		double val=(double)(n+1);
		double val1=n;
		val1=1.0/val1;
		val=pow(val,val1);

		ans/=val;

		printf("%.6f\n", ans);
	}

	return 0;
}