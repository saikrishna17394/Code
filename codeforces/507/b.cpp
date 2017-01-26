#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

lli dist(lli x,lli y) {
	return x*x+y*y;
}

int main(){ 
	// cin.sync_with_stdio(false);
	lli r,x,y,x1,Y1;

	cin>>r>>x>>y>>x1>>Y1;

	lli val1=dist(x-x1,y-Y1);

	lli val=sqrt(val1);

	lli ans=val/(2*r);

	if(val%(2*r)!=0 || val*val!=val1)
		ans++;
	cout<<ans<<endl;

	return 0;
}