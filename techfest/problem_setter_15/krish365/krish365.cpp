#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	long long int n,A[100000],B[100000];

	cin>>n;

	for(int i=0;i<n;i++)
		cin>>A[i]>>B[i];

	long long int l=1,r=(long long int)1e11;

	while(l<r) {
		long long int mid=(l+r)/2,cur=mid;

		bool ok=true;

		for(int i=0;i<n;i++) {
			if(cur<A[i]) {
				ok=false;
				break;
			}
			cur-=A[i];
			cur+=B[i];
		}
		if(!ok)
			l=mid+1;
		else
			r=mid;
	}

	cout<<l<<endl;
	return 0;
}