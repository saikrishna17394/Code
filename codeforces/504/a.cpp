#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

int n;
int d[1<<16],s[1<<16];

vector<ii> ans;

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>n;

	set<ii> m;

	for(int i=0;i<n;i++) {
		cin>>d[i]>>s[i];
		m.insert(ii(d[i],i));
		// cout<<" "<<d[i]<<" "<<i<<endl;
	}

	while(!m.empty()) {
		ii v=*m.begin();
		// cout<<v.first<<" a  "<<v.second<<endl;
		if(v.first==0) {
			m.erase(v);
			continue;
		}
		// cout<<v.second<<" b "<<s[v.second]<<endl;
		ans.push_back(ii(v.second,s[v.second]));
		
		int b=s[v.second];
		s[b]^=v.second;

		m.erase(v);
		v.first--;
		if(v.first!=0)
			m.insert(v);

		m.erase(ii(d[b],b));
		d[b]--;
		if(d[b]!=0)
			m.insert(ii(d[b],b));
	}
	cout<<ans.size()<<endl;

	for(int i=0;i<ans.size();i++) {
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}