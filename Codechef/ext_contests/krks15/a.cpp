#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;


int main(){ 
	int t,n;

	cin>>t;

	while(t--) {
		int num;
		cin>>n;
		map<int,int> m;

		for(int i=0;i<n;i++) {
			cin>>num;
			m[num]++;
		}

		int ans=0;

		for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
			if(it->second>1)
				ans++;
		cout<<ans<<endl;
	}

	return 0;
}