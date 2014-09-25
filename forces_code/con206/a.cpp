#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k,d;

	scanf("%d %d",&k,&d);

	if(d) {
		printf("%d",d);

		for(int i=1;i<k;i++)
			printf("0");
		printf("\n");
	}
	else if(k==1) {
		printf("0\n");
	}
	else
		printf("No solution\n");

	return 0;
}