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
#define inf 1999999999
#define lim 10000000

using namespace std;

int main() {
	int n;
	int ans=0;

	string s;
	cin>>n;

	while(n--) {
		cin>>s;
		if(s[1]=='+')
			ans++;
		else
			ans--;
	}
	cout<<ans<<endl;

	return 0;
}