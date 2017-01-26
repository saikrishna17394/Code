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

using namespace std;

map<vector<int>,lli> m;

lli pow1(lli n,lli k) {
	lli ans=1;
	while(k) {
		if(k&1)
			ans=(ans*n)%mod;
		n=(n*n)%mod;
		k>>=1;
	}
	return ans;
}
lli fun(lli n,lli x,lli y,lli z) {
	// if(x<0 || y<0 || z<0)
	// 	return 0;
	if((x+y+z)>n)
		return 0;
	if(n==0) {
		return 1;
	}
	vector<int> v;
	v.push_back(n);
	v.push_back(x);
	v.push_back(y);
	v.push_back(z);
	if(m.find(v)!=m.end())
		return m[v];
	if(x<=0 && y<=0 && z<=0) {
		return pow1(3,n);
	}
	lli ans=0;
	if(x>0)
		ans=(ans+fun(n-1,x-1,y,z))%mod;
	else
		ans=(ans+fun(n-1,0,y,z))%mod;
	if(y>0)
		ans=(ans+fun(n-1,x,y-1,z))%mod;
	else
		ans=(ans+fun(n-1,x,0,z))%mod;
	if(z>0)
		ans=(ans+fun(n-1,x,y,z-1))%mod;
	else
		ans=(ans+fun(n-1,x,y,0))%mod;
	m[v]=ans;
	return ans;
}
int main() {

	cout<<fun(10000,2300,2700,1100)<<endl;

	return 0;
}