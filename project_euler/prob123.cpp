#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define lim 10000000

using namespace std;

int B[lim+1];lli A[1000000]={0};lli cnt=1;

int main() {
	lli k=sqrt(lim);

	for(lli i=2;i<=k;i++) {
		if(B[i]==0) {
			for(lli j=i*i;j<=lim;j+=i)
				B[j]=i;
		}
	}

	for(int i=2;i<=lim;i++)
		if(B[i]==0)
			A[cnt++]=i;

	cout<<cnt<<endl;
	for(lli i=7037;i<cnt;i+=2) {
		if((A[i]*i*2)>10000000000) {
			cout<<i<<endl;
			break;
		}
	}


	return 0;
}