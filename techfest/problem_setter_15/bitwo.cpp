#include <cstdio>
#include <iostream>
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
#define inf (lli)1e12

using namespace std;

lli q,a,b,ans;
map<lli,int> m;

int main() {

	for(lli i=3;;i++) {
		lli val=1+i;
		lli num=i*i;
		val+=num;
		
		if(2*val>inf)
			break;
		while(2*val<=inf) {
			if(m.find(2*val)==m.end())
				m[2*val]=1;
			num*=i;
			val+=num;
		}
	}

	int idx=0;
	m[2]=1;

	for(map<lli,int>::iterator it=m.begin();it!=m.end();it++) {
		it->second=idx++;
		// cout<<it->first<<endl;
	}
	// cout<<m.size()<<" "<<idx<<endl;
	cin>>q;
	while(q--) {
		cin>>a>>b;
		map<lli,int>::iterator it;
		it=m.upper_bound(b);
		if(it==m.end())
			ans=m.size();
		else
			ans=it->second;

		it=m.lower_bound(a);
		if(it==m.end())
			ans-=m.size();
		else
			ans-=it->second;
		cout<<ans<<endl;
	}
	return 0;
}