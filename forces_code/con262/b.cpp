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

lli sum_of(lli n) {
	lli ret=0;
	while(n) {
		ret+=n%10;
		n/=10;
	}
	return ret;
}

int main() {
	lli a,b,c,x;

	cin>>a>>b>>c;

	vector<lli> ans;

	for(lli i=1;i<82;i++) {
		lli val=1;
		for(lli j=0;j<a;j++)
			val*=i;
		val*=b;
		val+=c;

		if(sum_of(val)==i && val>0 && val<1000000000) {
			ans.push_back(val);
		}
	}
	sort(ans.begin(),ans.end());

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	if(ans.size()>0)
		cout<<endl;
	return 0;
}