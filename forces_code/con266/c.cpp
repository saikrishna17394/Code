#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999
#define lim 10000000

using namespace std;

lli n,A[500000],sum=0;

int main() {
	cin>>n;

	for(int i=0;i<n;i++) {
		cin>>A[i];
		sum+=A[i];
	}

	if(n<3 || sum%3!=0) {
		printf("0\n");
		return 0;
	}

	lli val=sum/3;
	lli ans=0,num=0;

	sum-=(A[n-1]+A[n-2]);

	lli sum1=A[n-1];


	for(int i=n-3;i>=0;i--) {
		if(sum1==val)
			num++;
		// cout<<i<<" "<<sum<<" "<<sum1<<"w  "<<num<<endl;
		if(sum==val)
			ans+=num;

		sum-=A[i];
		sum1+=A[i+1];		
	}

	cout<<ans<<endl;
	return 0;
}