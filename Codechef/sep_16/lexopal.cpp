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

		bool ok =true;
		int n = s.length();
		for(int i=0;i<=(n-i-1);i++) {
			if(s[i] == s[n-i-1]) {
				if(s[i] == '.') {
					s[i]='a';
					s[n-i-1]='a';
				}
			}
			else if(s[i] == '.') {
				s[i] = s[n-i-1];
			}
			else if(s[n-i-1] == '.') {
				s[n-i-1] = s[i];
			}
			else {
				ok = false;
				break;
			}
		}

		if(!ok)
			printf("-1\n");
		else
			cout<<s<<endl;

	}


	return 0;
}