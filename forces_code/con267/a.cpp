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
	int n,a,b,ans=0;

	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>a>>b;
		if((b-a)>=2)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}