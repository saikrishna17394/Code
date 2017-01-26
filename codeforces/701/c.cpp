#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n;
string s;

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n;
	cin>>s;

	map<char,int> m;

	for(int i=0;i<n;i++) {
		m[s[i]]=0;
	}

	int val=m.size();

	int l=0,r=0;

	m[s[0]]++;

	int ans=inf;
	if(val==1)
		ans=1;

	int cur=1;
	for(int i=1;i<n;i++) {
		r=i;

		if(m[s[i]]==0) {
			cur++;
		}
		m[s[i]]++;

		while(m[s[l]]>1) {
			m[s[l]]--;
			l++;
		}

		if(cur==val) {
			ans=min(ans,r-l+1);
		}
	}

	cout<<ans<<endl;
	return 0;
}