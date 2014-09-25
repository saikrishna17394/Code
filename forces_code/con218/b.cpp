#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

map<ii,int> m;

int fun(int a,int b) {
	if(a==b)
		return 0;
	if(a>b)
		swap(a,b);

	if(m.find(ii(a,b))!=m.end())
		return m[ii(a,b)];

	int ret=inf;

	if(b%2==0)
		ret=min(ret,1+fun(a,b/2));
	if(b%3==0)
		ret=min(ret,1+fun(a,b/3));
	if(b%5==0)
		ret=min(ret,1+fun(a,b/5));

	m[ii(a,b)]=ret;
	// cout<<a<<" "<<b<<" "<<ret<<endl;
	return ret;

}
int main() {
	int a,b,ans;
	cin>>a>>b;

	ans=fun(a,b);

	if(ans==inf)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;

	return 0;
}