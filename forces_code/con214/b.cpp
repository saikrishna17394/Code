#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define inf 999999999
typedef long long int lli;

int main() {
	int n,k,A[100000],ans,ind,val;

	cin>>n>>k;

	for(int i=0;i<n;i++)
		cin>>A[i];

	ind=0;
	ans=inf;
	for(int i=0;i<k;i++) {
		val=0;
		for(int j=i;j<n;j+=k)
			val+=A[j];
		if(val<ans) {
			ans=val;
			ind=i+1;
		}
	}

	printf("%d\n", ind);
	return 0;
}