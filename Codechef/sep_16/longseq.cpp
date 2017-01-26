#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 300010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int main() {
	int t;

	cin>>t;

	while(t--) {
		string s;

		cin>>s;

		int val = 0;
		for(int i=0;i<s.length();i++) {
			if(s[i]=='0')
				val++;
		}

		int n = s.length();

		if(val==1 || val==(n-1))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}