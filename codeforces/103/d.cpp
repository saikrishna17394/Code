#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 300010

using namespace std;


int n,q,a,b;
int A[lim];
ii B[lim];
// map<ii,lli> m;
vector<ii> v[700][700];
lli C[lim];


int main(){ 
	// cin.sync_with_stdio(false);
	cin>>n;

	for(lli i=1;i<=n;i++)
		cin>>A[i];

	cin>>q;

	int k=sqrt(n);

	for(int i=0;i<q;i++) {
		cin>>B[i].first>>B[i].second;	
		// m[B[i]]=-1;
		if(B[i].second<=k) {
			v[B[i].second][B[i].first%B[i].second].push_back(ii(B[i].first,i));
		}
	}

	for(int j=1;j<=k;j++) {
		for(int i=0;i<j;i++) {
			lli val=0;
			sort(v[j][i].begin(),v[j][i].end());

			int idx=n-(n%j)+i;
			if(idx>n)
				idx-=j;

			for(int a=v[j][i].size()-1;a>=0;a--) {
				int u=v[j][i][a].first;
				while(idx>=u) {
					val+=(lli)A[idx];
					idx-=j;
				}
				C[v[j][i][a].second]=val;
			}

		}
	}

	for(int i=0;i<q;i++) {
		if(B[i].second<=k) {
			cout<<C[i]<<endl;
			continue;
		}
		lli val=0;
		for(int j=B[i].first;j<=n;j+=B[i].second)
			val+=(lli)A[j];
		cout<<val<<endl;
	}

	return 0;
}