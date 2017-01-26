#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

lli t,x,y,k;

int main() {
	cin>>t;

	while(t--) {
		cin>>x>>y;

		lli r=x/y;
		if(x%y!=0)
			r++;
		cout<<r<<endl;

	}

	return 0;
}