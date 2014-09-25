#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	double A[4000];
	int n,val=1,num;

	scanf("%d",&n);

	for(int i=0;i<2*n;i++) {
		cin>>A[i];
		num=A[i];
		A[i]-=num;
	}

	sort(A,A+2n);

	


	return 0;
}