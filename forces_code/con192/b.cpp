#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int A[1001]={0},n,m,a,b,x;

	scanf("%d %d",&n,&m);

	for(int i=0;i<m;i++) {
		scanf("%d %d",&a,&b);
		A[a]=1;
		A[b]=1;
	}

	for(int i=1;i<=n;i++)
		if(A[i]==0) {
			x=i;
			break;
		}

	printf("%d\n",n-1);

	for(int i=1;i<=n;i++) {
		if(i!=x)
			printf("%d %d\n",i,x);
	}
	return 0;
}