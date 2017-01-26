#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 10010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

string s, cur;
set<string> ans;
int n;

int dp[lim][2];

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>s;

	n = s.length();

	memset(dp, 0, sizeof dp);

	if(n >= 7) {
		cur = s.substr(n-2,2);
		ans.insert(cur);
		dp[n-3][0]=1;
	}

	if(n >= 8) {
		cur = s.substr(n-3,3);
		ans.insert(cur);
		dp[n-4][1]=1;
	}

	for(int i = n-3; i >= 6; i--) {
		if(dp[i][0] == 1) {
			if((s[i] != s[i+2]) || (s[i-1] != s[i+1]) ) {
				dp[i-2][0] = 1;
				cur = s.substr(i-1,2);
				ans.insert(cur);
			}
		}

		if(dp[i][1] == 1) {
			dp[i-2][0] = 1;
			cur = s.substr(i-1,2);
			ans.insert(cur);
		}


		if(i >= 7 && (dp[i][1] == 1) ) {
			if((s[i] != s[i+3]) || (s[i-1] != s[i+2]) || (s[i-2] != s[i+1])) {
				dp[i-3][1] = 1;
				cur = s.substr(i-2, 3);
				ans.insert(cur);
			}
		}

		if(i >= 7 && (dp[i][0] == 1)) {
			dp[i-3][1] = 1;
			cur = s.substr(i-2, 3);
			ans.insert(cur);			
		}
	}
	cout<<ans.size()<<endl;
	// cout<<"sdfds]\n";

	for(set<string>::iterator it = ans.begin(); it!=ans.end(); it++) {
		cout<<*it<<endl;
	}
	return 0;
}