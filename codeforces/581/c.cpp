#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ii pair<int,int>
#define mod 1000000007
#define inf 999999999
#define lim 100010

using namespace std;

int n,k,A[lim];

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n>>k;

	int val=0;

	vector<int> v;
	int ans=0;
	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		int rem=A[i]%10;
		ans+=A[i]/10;
		if(rem>0) {
			v.push_back(10-rem);
			A[i]+=(10-rem);
		}
		if(A[i]<100)
			val+=(100-A[i]);
	}

	sort(v.begin(),v.end());

	for(int i=0;i<v.size();i++) {
		if(k>=v[i]) {
			k-=v[i];
			ans++;
		}
	}

	ans+=min(val,k)/10;

	printf("%d\n", ans);

	return 0;
}