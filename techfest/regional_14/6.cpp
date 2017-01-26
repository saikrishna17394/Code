#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <vector>
#define lli long long int
#define lim 1000200
#define mod 1000000007
#define ii pair<int,int>

using namespace std;

map<ii,int> m1;
int fun(int n,int m) {
	if(n<0)
		return 0;
	if(m==1)
		return 1;
	if(m1.find(ii(n,m))!=m1.end())
		return m1[ii(n,m)];

	int ans=0;
	for(int i=0;i*m<=n;i++) {
		ans=(ans+fun(n-i*m,m-1) )%mod;
	}
	m1[ii(n,m)]=ans;
	return ans;
}

int main() {
	cout<<fun(90000,10000)<<endl;


	return 0;
}