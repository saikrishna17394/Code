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

const double pi = 2 * acos(0.0);

string s,s1;
int n;
string q[100000];

lli A[10];

int main() {
	cin>>s;

	cin>>n;
	for(int i=0;i<n;i++)
		cin>>q[i];

	for(int i=0;i<10;i++)
		A[i]=i;

	for(int i=n-1;i>=0;i--) {
		// s1=q[i].substr(3);

		int idx=q[i][0]-'0';

		
		lli val=0;

		for(int j=3;j<q[i].size();j++) {
			val=(val*10+A[q[i][j]-'0'])%mod;
		}
		A[idx]=val;
	}

	lli ans=0;

	for(int i=0;i<s.size();i++)
		ans=(ans*10+A[s[i]-'0'])%mod;

	printf("%lld\n", ans);
	return 0;
}