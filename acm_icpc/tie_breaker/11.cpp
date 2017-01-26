#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 999999999
#define lim 100010

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> ii;

using namespace std;

int n,k,A[10000];

int main() {
	cin>>n>>k;

	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A,A+n);
	k--;

	cout<<A[k]<<endl;

	return 0;
}