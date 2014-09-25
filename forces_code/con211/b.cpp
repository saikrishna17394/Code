#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<char,int> ii;

vector<ii> v;

int main() {
	int n,k,A[200000];

	cin>>n;
	cin>>k;

	for(int i=1;i<=n;i++)
		cin>>A[i];

	int sum=0,ans,ind=1;

	for(int i=1;i<=k;i++)
		sum+=A[i];
	ans=sum;

	for(int i=2;(i+k-1)<=n;i++) {
		sum-=A[i-1];
		sum+=A[i+k-1];
		if(sum<ans) {
			ans=sum;
			ind=i;
		}
	}
	cout<<ind<<endl;
	return 0;
}