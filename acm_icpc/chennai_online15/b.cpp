#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int t,n;
int A[lim];

int main(){ 
	cin>>t;

	while(t--) {
		cin>>n;

		int val=0;

		for(int i=0;i<n;i++) {
			scanf("%d",&A[i]);

			if(i>0 && A[i]==-1)
				val++;
		}

		double ans=(double)val;

		ans/=2.0;

		ans+=1.0;

		printf("%.6f\n", ans);

	}

	return 0;
}