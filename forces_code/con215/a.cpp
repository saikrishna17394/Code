#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 99999999
typedef long long int lli;

int main() {
	int n,d,A[100],ans,m;

	cin>>n>>d;

	for(int i=0;i<n;i++)
		cin>>A[i];

	cin>>m;
	sort(A,A+n);
	int val=min(m,n);
	ans=0;
	for(int i=0;i<val;i++)
		ans+=A[i];

	if(m>n)
		ans-=(m-n)*d;

	cout<<ans<<endl;

	return 0;
}