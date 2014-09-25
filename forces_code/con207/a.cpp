#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,A[100],x,y,a=0,b=0;

	scanf("%d",&n);

	for(int i=0;i<n;i++) {
		scanf("%d",&A[i]);
		b+=A[i];
	}
	scanf("%d %d",&x,&y);

	for(int i=1;i<=n;i++) {
		if(a>=x && a<=y && b>=x && b<=y) {
			printf("%d\n", i);
			return 0;
		}
		a+=A[i-1];
		b-=A[i-1];
	}
	printf("0\n");
	return 0;
}