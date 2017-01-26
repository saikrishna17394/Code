#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,A[100];

int B[100]={0};

int main(){ 
	// cin.sync_with_stdio(false);
	cin>>n;

	int sum = 0;

	for(int i=0;i<n;i++) {
		cin>>A[i];
		sum+=A[i];
	}
	sum*=2;
	sum/=n;

	for(int i=0;i<n;i++) {
		if(B[i]==1)
			continue;

		for(int j=i+1;j<n;j++) {
			if(B[j]==1)
				continue;
			if((A[i]+A[j])==sum) {
				B[j]=1;
				cout<<i+1<<" "<<j+1<<endl;
				break;
			}
		}
	}

	return 0;
}