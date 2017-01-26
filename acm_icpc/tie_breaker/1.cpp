#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int t,n,k;

int main() {
	cin>>t;

	string s;

	while(t--) {
		cin>>s;
		cin>>k;

		int val=0;
		for(int i=0;i<s.length();i++) {
			val*=10;
			val+=(s[i]-'0');
			val%=k;
		}

		if(val==0)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}