#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;


int main() {
	lli a,b;
	cin>>a>>b;
	lli ans=b*(b-1);
	ans/=2;

	ans%=mod;

	lli val=a*(a+1);
	val/=2;
	val%=mod;
	val=(val*b)%mod;
	val+=a;
	val%=mod;

	ans=(ans*val)%mod;
	cout<<ans<<endl;

	return 0;
}