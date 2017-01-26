#include <iostream>

using namespace std;

long long int n,A[100000],B[100000],ans=0,cur=0;

int main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>A[i]>>B[i];
		if(A[i]>cur) {
			ans+=(A[i]-cur);
			cur+=(A[i]-cur);
		}
		cur-=A[i];
		cur+=B[i];
	}
	cout<<ans<<endl;
	return 0;
}