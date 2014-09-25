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

int main() {
	int n;
	string s,s1;
	cin>>n>>s;

	int val=0;

	int carry=1;

	for(int i=0;i<n;i++) {
		if(s[i]=='0'){
			s1[i]=s[i]+carry;
			carry=0;
		}
		else {
			if(carry)
				s1[i]='0';
			else {
				s1[i]='1';
				carry=0;
			}
		}
	}

	int ans=0;

	for(int i=0;i<n;i++)
		if(s[i]!=s1[i])
			ans++;

	printf("%d\n", ans);
	return 0;
}