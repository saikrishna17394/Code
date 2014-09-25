#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,num,a=0,b=0;

	scanf("%d",&n);

	for(int i=0;i<n;i++) {
		scanf("%d",&num);
		if(num==0)
			a++;
		else
			b++;
	}

	if(a==0)
		printf("-1\n");
	else if(b<9)
		printf("0\n");
	else {
		for(int i=0;i<b/9;i++) {
			for(int j=0;j<9;j++)
				printf("5");
		}
		for(int i=0;i<a;i++)
			printf("0");
		printf("\n");
	}

	return 0;
}