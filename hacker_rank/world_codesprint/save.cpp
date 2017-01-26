#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int main() {
	string s;

	cin>>s;

	int ans=0;

	for(int i=0;i<s.length();i+=3) {
		if(s[i]!='S')
			ans++;
		if(s[i+1]!='O')
			ans++;
		if(s[i+2]!='S')
			ans++;
	}

	printf("%d\n", ans);
	return 0;
}