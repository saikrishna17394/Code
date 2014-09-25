#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<char,int> ii;


int main() {
	int n,k;
	cin>>n;

	if(n==0)
		printf("O-|-OOOO\n");
	while(n) {
		k=n%10;

		if(k<5) {
			printf("O-|");
		}
		else {
			printf("-O|");
			k-=5;
		}

		for(int i=0;i<k;i++)
			printf("O");
		printf("-");
		for(int i=0;i<(4-k);i++)
			printf("O");
		printf("\n");
		n/=10;
	}

	return 0;
}