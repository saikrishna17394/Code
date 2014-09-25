#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
using namespace std;


int main() {
	unsigned long long int A[1000001],t,n,big=0;
	A[0]=0;
	A[1]=1;
	for(unsigned long long int i=2;i<=1000000;i++)
		A[i]=2*A[i-1]+i/2+i-A[i-2];

	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		printf("%lld\n", A[n]);
	}
	return 0;
}