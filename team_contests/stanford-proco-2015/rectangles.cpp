#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<long long int,pair<int,int> > lii;

using namespace std;

map<lii,int> m;
ii A[1000];
int n;

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i].first>>A[i].second;


	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int x=A[i].first+A[j].first;
			int y=A[i].second+A[j].second;
			int dist=(A[i].first-A[j].first)*(A[i].first-A[j].first);
			dist+=(A[i].second-A[j].second)*(A[i].second-A[j].second);
			m[make_pair(dist,ii(x,y))]++;
			// cout<<dist<<" "<<x<<" "<<y<<endl;

		}
	}

	int ans=0;

	for(map<lii,int>::iterator it=m.begin();it!=m.end();it++) {
		int val=it->second;
		val*=(val-1);
		val/=2;
		ans+=val;
	}

	cout<<ans<<endl;

	return 0;
}