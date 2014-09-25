#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int n,d,A[50],ans,ind,val,days[100000];

	scanf("%d %d",&n,&d);

	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

	sort(A,A+n);

	ans=0;
	ind=0;
	for(int i=0;i<n;i++,ind++) {
		if(d>=(A[i]-ans))
			ans+=A[i];
		else {
			break;
		}
	}
	printf("%d ",ans);
	days[0]=0;
	for(int i=0;i<ind;i++) {

	}
	return 0;
}