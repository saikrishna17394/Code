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
#define ii pair<long long int,long long int>

#define mod 1000000007
#define inf (lli)1e16
#define lim 1000001

using namespace std;

lli len(lli n) {
	lli ret=0;
	while(n>0) {
		n/=10;
		ret++;
	}
	return ret;
}

map<lli,int> m;
vector<lli> v;

int main() {
	lli end=(lli)1e18;

	for(lli i=1;i<10;i++) {
		v.push_back(i);
		v[i]=1;
		m[i]=1;
	}

	for(int i=0;i<v.size();i++) {
		lli num=v[i];
		for(lli j=1;j<19;j++) {
			if(num>end)
				break;
			if(len(num)==j) {
				if(m.find(num)==m.end()) {
					v.push_back(num);
					m[num]=1;
				}
			}
			num+=v[i];
		}
	}

	lli t,l,r;

	cin>>t;

	while(t--) {
		cin>>l>>r;

		lli ans=0;

		for(int i=0;i<v.size();i++) {
			if(v[i]>=l && v[i]<=r)
				ans++;
		}
		if(l==0)
			ans++;
		printf("%lld\n", ans);
	}
	return 0;
}