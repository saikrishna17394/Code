#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n,m,A[100],B[100],a=1000,b=1000,a1=0;

	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		a=min(A[i],a);
		a1=max(A[i],a1);
	}

	for(int i=0;i<m;i++) {
		scanf("%d",&B[i]);
		b=min(b,B[i]);
	}

	if(a1>=b || 2*a>a1)
		printf("-1\n");
	else
		printf("%d\n", a1);

	return 0;
}