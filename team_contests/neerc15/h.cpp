#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;


int main(){ 
	// freopen("easy.in", "r", stdin);
	// freopen("inp", "r", stdin);
	// freopen("easy.out", "w", stdout);

	while(1) {
		string s;
		cin>>s;

		int hash=0;
		int val=1;
		for(int i=s.length()-1;i>=0;i--) {
			hash+=s[i]*val;
			val*=31;
		}

		cout<<hash<<endl;
	}
	return 0;
}