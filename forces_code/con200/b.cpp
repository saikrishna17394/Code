#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int A[3],B[3],num;

	for(int i=0;i<3;i++) {
		scanf("%d",&A[i]);
		B[i]=A[i];
	}

	sort(A,A+3);

	if(A[2]>A[1]+A[0])
		printf("Impossible\n");
	else if((A[1]+A[0]-A[2])&1)
		printf("Impossible\n");
	else {
		num=(A[1]+A[0]-A[2])/2;

		if(B[0]==A[2])
			cout<<B[1]-num<<" "<<num<<" "<<B[2]-num<<endl;
		else if(B[1]==A[2])
			cout<<B[0]-num<<" "<<B[2]-num<<" "<<num<<endl;
		else
			cout<<num<<" "<<B[1]-num<<" "<<B[0]-num<<endl;
	}
	
	return 0;
}