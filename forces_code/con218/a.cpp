#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

int main() {
	int n,k,A[100],B[100][2]={0},ans;

	cin>>n>>k;

	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<n;) {
		for(int j=0;j<k;j++,i++) {
			if(A[i]==1)
				B[j][0]++;
			else
				B[j][1]++;
		}
	}
	ans=0;

	for(int i=0;i<k;i++)
		ans+=min(B[i][0],B[i][1]);
	cout<<ans<<endl;

	return 0;
}