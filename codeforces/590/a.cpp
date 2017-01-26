#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 500010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,A[lim];
vector<ii> v;

int main(){ 
	// cin.sync_with_stdio(false);
	
	cin>>n;

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	int ans=0;

	int val=1;
	for(int i=1;i<n;i++) {
		if(A[i]!=A[i-1])
			val++;
		else {
			ans=max(ans,(val-1)/2);
			if(val>2)
				v.push_back(ii(i-val,i-1));
			val=1;
		}
	}
	ans=max(ans,(val-1)/2);
	if(val>2)
		v.push_back(ii(n-val,n-1));

	cout<<ans<<endl;

	for(int i=0;i<v.size();i++) {
		ii p=v[i];

		if(A[p.first]==A[p.second]) {
			for(int j=p.first;j<=p.second;j++)
				A[j]=A[p.first];
		}
		else {
			for(int j=p.first;j<=p.second;j++) {
				if((j-p.first)<=(p.second-p.first)/2)
					A[j]=A[p.first];
				else
					A[j]=A[p.second];
			}
		}
	}

	for(int i=0;i<n;i++)
		printf("%d ",A[i] );

	printf("\n");
	return 0;
}