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

lli len(lli n) {
	lli ret=0;
	while(n>0) {
		ret++;
		n/=2;
	}
	return ret;
}

lli solve(lli l,lli r) {
	if(l==r)
		return l;
	if(l==0)
		l++;
	if(len(l)!=len(r)) {
		lli ret=0;
		lli val=len(r);
		for(lli i=0;i<val;i++) {
			ret*=2;
			ret++;
		}
		if(ret==r)
			return ret;
		ret/=2;
		return ret;
	}
	lli ret=1;
	lli val=len(l);

	for(lli i=1;i<val;i++)
		ret*=2;
	return ret+solve(l%ret,r%ret);
}
int main() {
	lli n,l,r;

	cin>>n;

	while(n--) {
		cin>>l>>r;

		if(l==r) {
			cout<<l<<endl;
			continue;
		}

		if(l==0)
			l++;

		cout<<solve(l,r)<<endl;
	}


	return 0;
}