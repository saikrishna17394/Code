#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int main(){ 
	// cin.sync_with_stdio(false);
	int a,b;
	cin>>a>>b;

	if(a>b)
		swap(a,b);

	cout<<a<<" "<<(b-a)/2<<endl;

	return 0;
}