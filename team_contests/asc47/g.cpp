#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<long long int,long long int> ii;

using namespace std;

int main(){ 
	// freopen("greater.in", "r", stdin);
	freopen("inp", "r", stdin);
	freopen("greater.out", "w", stdout);

	int d,b;

	while(1) {
		cin>>d>>b;

		if(d==0)
			break;

		double ans=pow((double)b,(double)d);

		ans=1.0/ans;

		ans=1.0-ans;

		ans/=2.0;

		printf("%.6f\n", ans);
	}


	return 0;
}