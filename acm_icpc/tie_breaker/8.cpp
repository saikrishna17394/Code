#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

string s;
int d,k;

map<vector<int>,vector<lli> > m;

vector<lli> solve(vector<int> v) {
	if(m.find(v)!=m.end())
		return m[v];

	vector<lli> ret(d,0);

	for(int i=0;i<10;i++) {
		if(v[i]==0)
			continue;
		v[i]--;
		vector<lli> ans=solve(v);
		v[i]++;
		for(int j=0;j<d;j++) {
			int idx=(j*10+i)%d;
			ret[idx]+=ans[j];
		}
	}
	m[v]=ret;
	// cout<<v[1]<<" "<<v[2]<<" "<<v[4]<<" : "<<ret[0]<<" "<<ret[1]<<endl;

	return ret;
}


int main() {
	cin>>s>>d>>k;

	vector<int> v(10,0);

	for(int i=0;i<s.length();i++) {
		v[s[i]-'0']++;
	}

	for(int i=0;i<10;i++) {
		vector<int> v1(10,0);
		v1[i]=1;

		vector<lli> ret(d,0);
		if(v[i]>0)
			ret[i%d]=1;

		m[v1]=ret;
	}

	vector<lli> ans=solve(v);

	cout<<ans[k]<<endl;

	return 0;
}