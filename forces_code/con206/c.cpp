#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n,l,r,ql,qr,A[100000],ans,val=0;

	scanf("%d %d %d %d %d",&n,&l,&r,&ql,&qr);

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		val+=A[i]*r;
	}

	ans=val+qr*(n-1);

	int a=1,b=n-1;
	for(int i=0;i<n;i++,a++,b--) {
		val-=A[i]*r;
		val+=A[i]*l;

		if(a<=b) {
			ans=min(ans,val+max(0,b-a-1)*qr);
		}
		else {
			ans=min(ans,val+(a-b-1)*ql);	
		}
	}

	printf("%d\n", ans);
	return 0;
}