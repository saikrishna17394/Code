#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

int main() {
	lli t,n,A[21],k;

	cin>>t;

	while(t--) {
		cin>>n>>k;

		lli sum=0;

		vector<lli> v,v1;
		for(int i=0;i<n;i++) {
			cin>>A[i];
			sum+=A[i];
			v.push_back(A[i]);
		}
		sort(v.begin(),v.end());

		if(sum%k!=0) {
			printf("no\n");
			continue;
		}

		sum/=k;
		while(v.size()!=0) {
			lli val=0;
			v1.clear();

			for(int i=v.size()-1;i>=0;i--) {
				if((val+v[i])<=sum) 
					val+=v[i];
				else
					v1.push_back(v[i]);
			}
			sort(v1.begin(),v1.end());

			v=v1;
		}

	}


	return 0;
}