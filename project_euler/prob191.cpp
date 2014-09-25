#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
using namespace std;

lli A[2][2][31],B[2][2][31],ans,ans1;
int main() {

	memset(A,0,sizeof A);

	A[1][1][2]=1;
	A[0][1][2]=1;
	A[1][0][2]=1;
	A[0][0][2]=1;

	A[0][0][3]=2;A[1][0][3]=2;A[0][1][3]=2;
	A[1][1][3]=1;

	int k=4;

	while(k<31) {

		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				A[j][0][k]+=A[i][j][k-1];
				if(i==0 || j==0) {
					A[j][1][k]+=A[i][j][k-1];
				}
			}
		}
	k++;
	}

	int l=30;
	ans=0;
	ans+=A[0][0][l]+A[1][0][l]+A[0][1][l]+A[1][1][l];

	ans+=(A[0][0][l-1]+A[1][0][l-1]+A[0][1][l-1]+A[1][1][l-1])*l;	

	ans+=(A[1][1][l-2])*2;

	for(int i=1;i<=(l-4);i++) {
		ans+=(A[0][1][i+1]+A[1][1][i+1])*(A[1][1][l-2-i]);
		ans+=A[1][1][i+1]*A[0][1][l-2-i];
	}


	cout<<ans<<endl;
	return 0;
}